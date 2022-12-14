#include <math.h>

#include "gtest/gtest.h"

#include "rec/audio/ammf_scaler/AudioTimeScaler.h"
#include "rec/audio/stretch/TestHarness.h"
#include "rec/audio/stretch/TimeScaler.h"
#include "rec/audio/stretch/Stretch.pb.h"

using namespace juce;

namespace rec {
namespace audio {
namespace stretch {

namespace {

float rampWave(int ramp, int scale) {
  return ((ramp + scale) % (2 * scale + 1) - scale) / float(scale);
}

void doInit(AudioTimeScaler* scaler) {
  Stretch desc;
  desc.set_channels(2);
  Init(desc, scaler);
}

}  // namespace

TEST(RecAudio, RampWave) {
  EXPECT_FLOAT_EQ(rampWave(0, 100), 0.0);
  EXPECT_FLOAT_EQ(rampWave(1, 100), 0.01);
  EXPECT_FLOAT_EQ(rampWave(100, 100), 1.0);
  EXPECT_FLOAT_EQ(rampWave(101, 100), -1.0);
  EXPECT_FLOAT_EQ(rampWave(102, 100), -0.99);
  EXPECT_FLOAT_EQ(rampWave(201, 100), 0.0);
}

TEST(RecAudio, AudioTimeScalerInitialize) {
  {
    AudioTimeScaler scaler;
    doInit(&scaler);

    EXPECT_EQ(scaler.GetOutputBufferSize(512), 0);
    EXPECT_EQ(scaler.GetOutputBufferSize(512), 1024);
    EXPECT_EQ(scaler.GetInputBufferSize(512), 1024);
    EXPECT_EQ(scaler.GetOutputBufferSize(512), 1024);
  }
  {
    AudioTimeScaler scaler;
    doInit(&scaler);

    EXPECT_EQ(scaler.GetInputBufferSize(512), 25600);
    EXPECT_EQ(scaler.GetInputBufferSize(512), 1024);
    EXPECT_EQ(scaler.GetOutputBufferSize(512), 1024);
    EXPECT_EQ(scaler.GetInputBufferSize(512), 1024);
  }
}

TEST(RecAudio, AudioTimeScaler) {
  const static unsigned int SAMPLES_PER_CHUNK = 128;
  float outputSamples1[SAMPLES_PER_CHUNK];
  float outputSamples2[SAMPLES_PER_CHUNK];
  float *outputSamples[] = { outputSamples1, outputSamples2 };

  AudioTimeScaler scaler;
  doInit(&scaler);

  int samplesOut = 0;
  int samplesIn = 0;
  float maxDiff = 0;

  for (int j = 0; j < 3; ++j) {
    unsigned int samplesToRead = scaler.GetInputBufferSize(SAMPLES_PER_CHUNK);
    unsigned int samplesToProcess = samplesToRead / 2;  // Why divide by 2?!?!?
    float* inputSamples1 = new float[samplesToProcess];
    float* inputSamples2 = new float[samplesToProcess];
    float *inputSamples[] = { inputSamples1, inputSamples2 };
    for (int i = 0; i < samplesToProcess; ++i)
      inputSamples[0][i] = inputSamples[1][i] =rampWave(samplesOut + i, 100);
    int samplesProcessed = scaler.Process(inputSamples, outputSamples,
                                          samplesToProcess, SAMPLES_PER_CHUNK);
    EXPECT_EQ(samplesProcessed, 128);

	delete inputSamples1;
	delete inputSamples2;

    // Make sure output is within 0.082 of the input.
    // Observed maxDiff is 0.0813631.
    for (int i = 0; i < samplesProcessed; ++i) {
      float inputSample = rampWave(samplesIn + i, 100);
      for (int j = 0; j < 2; ++j) {
        EXPECT_NEAR(inputSample, outputSamples[j][i], 0.085);
        maxDiff = std::max<float>(double(maxDiff), fabs(inputSample - outputSamples[j][i]));
      }
    }
    samplesIn += samplesProcessed;
    samplesOut += samplesToProcess;
  }
  if (false)
    DLOG(INFO) << "maxdiff " << maxDiff << std::endl;
}

}  // namespace stretch
}  // namespace audio
}  // namespace rec
