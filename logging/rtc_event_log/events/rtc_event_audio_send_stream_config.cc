/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "logging/rtc_event_log/events/rtc_event_audio_send_stream_config.h"

#include <memory>
#include <utility>

#include "absl/memory/memory.h"
#include "api/rtc_event_log/rtc_event.h"
#include "logging/rtc_event_log/rtc_stream_config.h"
#include "rtc_base/checks.h"

namespace webrtc {

RtcEventAudioSendStreamConfig::RtcEventAudioSendStreamConfig(
    std::unique_ptr<rtclog::StreamConfig> config)
    : config_(std::move(config)) {
  RTC_DCHECK(config_);
}

RtcEventAudioSendStreamConfig::RtcEventAudioSendStreamConfig(
    const RtcEventAudioSendStreamConfig& other)
    : RtcEvent(other.timestamp_us_),
      config_(std::make_unique<rtclog::StreamConfig>(*other.config_)) {}

RtcEventAudioSendStreamConfig::~RtcEventAudioSendStreamConfig() = default;

std::unique_ptr<RtcEventAudioSendStreamConfig>
RtcEventAudioSendStreamConfig::Copy() const {
  return absl::WrapUnique<RtcEventAudioSendStreamConfig>(
      new RtcEventAudioSendStreamConfig(*this));
}

}  // namespace webrtc
