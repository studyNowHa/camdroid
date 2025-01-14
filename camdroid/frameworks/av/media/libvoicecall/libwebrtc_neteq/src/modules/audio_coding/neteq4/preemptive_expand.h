/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_AUDIO_CODING_NETEQ4_PREEMPTIVE_EXPAND_H_
#define WEBRTC_MODULES_AUDIO_CODING_NETEQ4_PREEMPTIVE_EXPAND_H_

#include <assert.h>

#include "modules/audio_coding/neteq4/audio_multi_vector.h"
#include "modules/audio_coding/neteq4/time_stretch.h"
#include "system_wrappers/interface/constructor_magic.h"
#include "typedefs.h"

namespace webrtc {

// Forward declarations.
class BackgroundNoise;

// This class implements the PreemptiveExpand operation. Most of the work is
// done in the base class TimeStretch, which is shared with the Accelerate
// operation. In the PreemptiveExpand class, the operations that are specific to
// PreemptiveExpand are implemented.
class PreemptiveExpand : public TimeStretch {
 public:
  PreemptiveExpand(int sample_rate_hz, size_t num_channels,
                   const BackgroundNoise& background_noise)
      : TimeStretch(sample_rate_hz, num_channels, background_noise),
        old_data_length_per_channel_(-1),
        overlap_samples_(5 * sample_rate_hz / 8000) {
  }

  virtual ~PreemptiveExpand() {}

  // This method performs the actual PreemptiveExpand operation. The samples are
  // read from |input|, of length |input_length| elements, and are written to
  // |output|. The number of samples added through time-stretching is
  // is provided in the output |length_change_samples|. The method returns
  // the outcome of the operation as an enumerator value.
  ReturnCodes Process(const int16_t *pw16_decoded,
                      int len,
                      int old_data_len,
                      AudioMultiVector* output,
                      int16_t* length_change_samples);

 protected:
  // Sets the parameters |best_correlation| and |peak_index| to suitable
  // values when the signal contains no active speech.
  virtual void SetParametersForPassiveSpeech(size_t len,
                                             int16_t* w16_bestCorr,
                                             int* w16_bestIndex) const;

  // Checks the criteria for performing the time-stretching operation and,
  // if possible, performs the time-stretching.
  virtual ReturnCodes CheckCriteriaAndStretch(
      const int16_t *pw16_decoded, size_t len, size_t w16_bestIndex,
      int16_t w16_bestCorr, bool w16_VAD,
      AudioMultiVector* output) const;

 private:
  int old_data_length_per_channel_;
  int overlap_samples_;

  DISALLOW_COPY_AND_ASSIGN(PreemptiveExpand);
};

struct PreemptiveExpandFactory {
  PreemptiveExpandFactory() {}
  virtual ~PreemptiveExpandFactory() {}

  virtual PreemptiveExpand* Create(
      int sample_rate_hz,
      size_t num_channels,
      const BackgroundNoise& background_noise) const;
};

}  // namespace webrtc
#endif  // WEBRTC_MODULES_AUDIO_CODING_NETEQ4_PREEMPTIVE_EXPAND_H_
