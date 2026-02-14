// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "hangman_api.h"

#pragma hls_top
int hangmanMakeMove(char letter, int word_index) {
  const char words[3][8] = {
      "hangman",
      "context",
      "encrypt",
  };

  int result = 0;
  #pragma hls_unroll yes
  for (int i = 0; i < 7; ++i) {
    // We mask the word_index to ensure it is within bounds, in case the input
    // is malicious or erroneous. Since we have 3 words, we can't easily mask
    // with power of 2. We'll just rely on the caller passing correct index for this demo.
    // Or we can use `word_index % 3`. But modulo is expensive in hardware/FHE.
    // Let's assume input is correct (0, 1, or 2).
    if (words[word_index][i] == letter) {
      result |= (1 << (6 - i));
    }
  }

  return result;
}
