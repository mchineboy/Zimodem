#ifdef INCLUDE_SLIP
/*
   Copyright 2022-2024 Bo Zimmerman

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "lwip/raw.h"
#include "src/missing/slipif.h"

static ZSerial sserial;
class ZSLIPMode: public ZMode
{
private:
  void switchBackToCommandMode();
  String inPacket;
  bool started=false;
  bool escaped=false;
  raw_pcb *_pcb = 0;

public:
  static const char SLIP_END = '\xc0';
  static const char SLIP_ESC = '\xdb';
  static const char SLIP_ESC_END = '\xdc';
  static const char SLIP_ESC_ESC = '\xdd';
  void switchTo();
  void serialIncoming();
  void loop();
};

#endif /* INCLUDE_SLIP_ */
