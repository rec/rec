#!/usr/bin/python

import getopt
import glob
import os
import os.path
import re
import sys

import util

class Mover(object):
  NONE, START, BODY, END_NAME, END_GUARD, END = range(6)

  BLANK_PATTERN = '^\s+$'
  START_PATTERN = '^namespace \w+ {';
  END_PATTERN =  r'^}\s+// namespace \w+'
  GUARD_PATTERN =  r'^#endif\s+// __REC'

  FUNCTIONS = [(lambda path: '__' + '_'.join(p.upper() for p in path)),
               (lambda path: '#include "%s.h"' % '/'.join(path)),
               (lambda path: r'\b%s\b' % path[-1]),
               ]

  def __init__(self, fromFile, toFile, namespace, copy):
    self.state = Mover.NONE
    self.fromFile, self.toFile = self.check(fromFile, toFile)
    self.namespace = namespace
    self.copy = copy

    if namespace:
      namespace = namespace.split('/')
      fp = namespace + [os.path.basename(self.fromFile)]
      tp = namespace + [os.path.basename(self.toFile)]
    else:
      fp = util.pathParts(self.fromFile)
      tp = util.pathParts(self.toFile)
    names = tp[:-1]
    self.reps = [[f(fp), f(tp).replace(r'\b', '')] for f in Mover.FUNCTIONS]

    def bed(names, begin, end='\n'):
      return begin + (end + begin).join(names) + end + '\n'

    self.namespaceStart = bed(names, 'namespace ', ' {\n')
    self.namespaceEnd =  bed(reversed(names), '}  // namespace ')

  def check(self, f, t):
    f, t = os.path.abspath(f), os.path.abspath(t)

    if not os.path.exists(f):
      raise ValueError(f + " doesn't exist!")

    if os.path.isdir(f):
      raise ValueError(f + ' is a directory!')

    if os.path.isdir(t):
      t += ('/' + os.path.basename(f))

    if os.path.exists(t):
      raise ValueError(t + ' already exists.')

    return f,t

  def move(self):
    tempFile = self.toFile + '.tmp'
    util.run('cp %s %s' % (self.fromFile, tempFile))
    if not self.copy:
      util.run('git mv %s %s' % (self.fromFile, self.toFile))
      if os.path.exists(self.fromFile):
        util.run('mv -f %s %s' % (self.fromFile, self.toFile))

    with open(tempFile, 'r') as input:
      with open(self.toFile, 'w') as output:
        self.out = output
        for line in input:
          self.transition(self.toState(line), line)
          self.process(line)
        self.transition(Mover.END, 'ENDENDEND')
    os.remove(tempFile)

  def toState(self, line):
    if re.match(Mover.BLANK_PATTERN, line):
      return self.state

    if self.state is Mover.NONE:
      return re.match(Mover.START_PATTERN, line) and Mover.START or Mover.NONE

    if self.state is Mover.START:
      return re.match(Mover.START_PATTERN, line) and Mover.START or Mover.BODY

    if re.match(Mover.END_PATTERN, line):
      return Mover.END_NAME

    if re.match(Mover.GUARD_PATTERN, line):
      return Mover.END_GUARD

    return Mover.BODY

  def transition(self, state, line):
    if self.state != state:
      if self.state is Mover.START:
        self.out.write(self.namespaceStart)

      if state is Mover.BODY:
        if self.state is Mover.END_GUARD:
          for x in self.endCache:
            self.out.write(x)
        self.endCache = []

      if state is Mover.END_GUARD:
        if self.state is Mover.END_GUARD:
          raise ValueError('Two end guards!')
        self.out.write(self.namespaceEnd)
        self.namespaceEnd = ''

      if state is Mover.END:
        self.out.write(self.namespaceEnd)
        self.namespaceEnd = ''

    self.state = state

  def process(self, line):
    if self.state in [Mover.NONE, Mover.BODY, Mover.END_GUARD]:
      for pat, repl in self.reps:
        line = re.sub(pat, repl, line)
      self.out.write(line)

    elif self.state is Mover.END_NAME:
      self.endCache.append(line)

def parseArgs(args):
  optlist, args = getopt.getopt(args, 'cn:', ['copy', 'namespace='])
  namespace = None
  for name, value in optlist:
    if name == '-n' or name == '--namespace':
      namespace = value
      break

  for name, value in optlist:
    if name == '-c' or name == '--copy':
      return args, namespace, True

  return args, namespace, False

def move(args):
  args, namespace, copy = parseArgs(args)
  to = args.pop()
  files = []
  for arg in args:
    results = glob.glob(arg)
    if results:
      files.extend(results)
    else:
      print arg, "didn't match any files."

  if not args:
    print ('Usage: mover.py fromFile toFileOrDirectory\n'
           '       mover.py from [...from] toDirectory')

  elif len(args) > 1 and not os.path.isdir(to):
     print 'Can only move multiple files to a directory:', to

  else:
    for a in args:
      Mover(a, to, namespace, copy).move()

move(sys.argv[1:])
