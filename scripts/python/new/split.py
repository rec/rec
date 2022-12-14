#!/usr/bin/python

LINE_LENGTH = 78;

def split_suffix(filename, suffixes):
  for s in suffixes:
    if filename.endswith(s):
      return filename.split(s)[0], s

def maxSplit(s, splitters=' /;,', lineLength=LINE_LENGTH):
  s = s[0 : lineLength]
  finds = [i for i in map(s.rfind, splitters) if i >= 0]

  if finds:
    return max(finds)

  return -1

def splitLargeLines(lines, lineLength=LINE_LENGTH, maxLineLength=16380):
  for i, l in enumerate(lines):
    while len(l) > lineLength:
      loc = maxSplit(l)
      if loc is -1:
        break
      yield l[0 : loc + 1] + '"\n  "'
      l = l[loc + 1 : ]

    if len(l) > maxLineLength:
      raise ValueError, "Couldn't split line %d, len %d" % (i, l)

    yield l + '\n'
