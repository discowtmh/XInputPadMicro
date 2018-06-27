/*
     .k8GOGGNqkSFS5XkqXPSkSkkqXXFS5kSkSS15U22F2515U2uujuu1U1u2U1U2uUuFS.
   :0qE     JS5uuJuuFFX51jU2SSk12jU2SSXF5uuu15SFS5k12ujj21S5kFS5S12jJYu11
  5XS:        1UYYLu.   vUUX    U22r     SUF         SUF           ;YYLuU5
 1F5i  NNSkS7  2uLJui   51u     S5.      .PX         .XX           LJvLLu1.
 kUk  0iLk5FFu vuYY2:   5F    Xkk7        78    E0    i0    GEXPXk2uLLvLLuk
X25, 8O   2kX0  5YJUi   M    555    PkXk   i    q1FU   7    ONNkP12YLvLvLYS
S25  8888  888  5uY5         FuS    PS50   .    FuUU   7          uJvLvLLJ2i
kUF             SJjU.      P02UF    P25k   .    Su2Y   v          2LLvLvLL17
S21  XJj88  0u  1uY2.        X2k           .    k11E   v    7;ii:JuJvLvLvJ2:
2257 jqv   Pqq  1LJur         PP.          7    EX:    q    OqqXP51JYvLvYYS.
 X2F  kXkXSXk  kJYLU:   O     ,Z    0PXZ   i    ii    q0    i:::,,.jLLvLLuF'
 ik1k  ;qkPj  .uJvYu:   UN      :   XU2F   :         S5S           iJLLvjUF8
  :PSq       72uLLLui   uSi    .;   2uY1   r.       72j1           LYYLYJSU88
    XqE2   rP12juJuu1FX55U5FqXXSXkXF1juUkkPSXSPXPXPF1Jju5FkFSFXFSF5uujUu5j28V
      .uGOZESS5S5SFkkPkPkXkPXqXPXqXXFkSkkPXPXPkqSkSS1521252121U2u2u12Suv7

*
* Arduino Micro (Leonardo) XInput Pad Emulator firmware
*
* Copyright (c) 2017
* Bruno Freitas - bruno@brunofreitas.com
* Jon Wilson    - degenatrons@gmail.com
* Kevin Mackett - kevin@sharpfork.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "XInputPad.h"
#include "util.h"

void setup_pins(void);

int xinput_setup(void) {
    // Set clock @ 16Mhz
    CPU_PRESCALE(0);

    // Disable JTAG
    bit_set(MCUCR, 1 << JTD);
    bit_set(MCUCR, 1 << JTD);

    // Setup pins
    setup_pins();

    // Init XBOX pad emulation
    xbox_init(true);
}

void setup_pins(void) {

    // Setup pins
    bit_clear(DDRF, 1 << 7);
    bit_set(PORTF, 1 << 7);

    bit_clear(DDRF, 1 << 6);
    bit_set(PORTF, 1 << 6);

    bit_clear(DDRF, 1 << 5);
    bit_set(PORTF, 1 << 5);

    bit_clear(DDRF, 1 << 4);
    bit_set(PORTF, 1 << 4);

    bit_clear(DDRF, 1 << 1);
    bit_set(PORTF, 1 << 1);

    bit_clear(DDRF, 1 << 0);
    bit_set(PORTF, 1 << 0);

    bit_clear(DDRB, 1 << 3);
    bit_set(PORTB, 1 << 3);

    bit_clear(DDRB, 1 << 1);
    bit_set(PORTB, 1 << 1);

    bit_clear(DDRD, 1 << 6);
    bit_set(PORTD, 1 << 6);

    bit_clear(DDRB, 1 << 7);
    bit_set(PORTB, 1 << 7);

    bit_clear(DDRB, 1 << 6);
    bit_set(PORTB, 1 << 6);

    bit_clear(DDRB, 1 << 5);
    bit_set(PORTB, 1 << 5);

    bit_clear(DDRB, 1 << 4);
    bit_set(PORTB, 1 << 4);

    bit_clear(DDRE, 1 << 6);
    bit_set(PORTE, 1 << 6);

    bit_clear(DDRD, 1 << 7);
    bit_set(PORTD, 1 << 7);

    bit_clear(DDRC, 1 << 6);
    bit_set(PORTC, 1 << 6);

    bit_clear(DDRD, 1 << 4);
    bit_set(PORTD, 1 << 4);

    bit_clear(DDRD, 1 << 0);
    bit_set(PORTD, 1 << 0);

    bit_clear(DDRD, 1 << 1);
    bit_set(PORTD, 1 << 1);

    bit_clear(DDRD, 1 << 2);
    bit_set(PORTD, 1 << 2);

    bit_clear(DDRD, 1 << 3);
    bit_set(PORTD, 1 << 3);

    bit_clear(DDRB, 1 << 0);
    bit_set(PORTB, 1 << 0);

    bit_clear(DDRB, 1 << 2);
    bit_set(PORTB, 1 << 2);

    bit_clear(DDRC, 1 << 7);
    bit_set(PORTC, 1 << 7);
}
