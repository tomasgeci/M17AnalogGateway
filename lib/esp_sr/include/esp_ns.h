// Copyright 2015-2019 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License
#ifndef _ESP_NS_H_
#define _ESP_NS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NS_FRAME_LENGTH_MS 10          //Supports 10ms, 20ms, 30ms

/**
* The Sampling frequency (Hz) must be 16000Hz
*/

typedef void* ns_handle_t;

/**
 * @brief Creates an instance to the NS structure.
 *
 * @param frame_length_ms The length of the audio processing can be 10ms, 20ms, 30ms.
 *
 * @return
 *         - NULL: Create failed
 *         - Others: The instance of NS
 */
ns_handle_t ns_create(int frame_length_ms);

/**
 * @brief Feed samples of an audio stream to the NS and get the audio stream after Noise suppression.
 *
 * @param inst        The instance of NS.
 *
 * @param indata      An array of 16-bit signed audio samples.
 *
 * @param outdata     An array of 16-bit signed audio samples after noise suppression.
 *
 * @return None
 *
 */
void ns_process(ns_handle_t inst, int16_t *indata, int16_t *outdata);

/**
 * @brief Free the NS instance
 *
 * @param inst The instance of NS.
 *
 * @return None
 *
 */
void ns_destroy(ns_handle_t inst);

#ifdef __cplusplus
}
#endif

#endif //_ESP_NS_H_
