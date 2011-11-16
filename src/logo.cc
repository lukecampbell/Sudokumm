/*
 * Sudokumm 
 * Copyright 2011 Luke Campbell
 *
 * logo.cc
 *
 *  Created on: 14 November 2011
 *  Author: Luke campbell
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

const char *gplv2 =
"Sudokumm is a Graphical Sudoku Game\
Copyright (C) 2011  Luke Campbell\
\
This program is free software; you can redistribute it and/or\
modify it under the terms of the GNU General Public License\
as published by the Free Software Foundation; either version 2\
of the License, or (at your option) any later version.\
\
This program is distributed in the hope that it will be useful,\
but WITHOUT ANY WARRANTY; without even the implied warranty of\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\
GNU General Public License for more details.\
\
You should have received a copy of the GNU General Public License\
along with this program; if not, write to the Free Software\
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.";

/* XPM */


const char * sudokumm_xpm[] = {
"48 48 111 2",
"   c None",
".  c #FFFFFF",
"+  c #000000",
"@  c #1F1F1F",
"#  c #BFBFBF",
"$  c #1E1E1E",
"%  c #1D1D1D",
"&  c #1C1C1C",
"*  c #1B1B1B",
"=  c #1A1A1A",
"-  c #191919",
";  c #181818",
">  c #B6B6B6",
",  c #686868",
"'  c #424242",
")  c #0E0E0E",
"!  c #393939",
"~  c #969696",
"{  c #F0F0F0",
"]  c #171717",
"^  c #D5D5D5",
"/  c #464646",
"(  c #212121",
"_  c #C8C8C8",
":  c #161616",
"<  c #D6D6D6",
"[  c #090909",
"}  c #040404",
"|  c #909090",
"1  c #151515",
"2  c #F8F8F8",
"3  c #2E2E2E",
"4  c #030303",
"5  c #D7D7D7",
"6  c #8D8D8D",
"7  c #0A0A0A",
"8  c #6A6A6A",
"9  c #B4B4B4",
"0  c #ECECEC",
"a  c #696969",
"b  c #525252",
"c  c #141414",
"d  c #555555",
"e  c #656565",
"f  c #C9C9C9",
"g  c #131313",
"h  c #252525",
"i  c #CDCDCD",
"j  c #CCCCCC",
"k  c #7E7E7E",
"l  c #121212",
"m  c #0D0D0D",
"n  c #CECECE",
"o  c #5C5C5C",
"p  c #383838",
"q  c #676767",
"r  c #3A3A3A",
"s  c #111111",
"t  c #0B0B0B",
"u  c #6E6E6E",
"v  c #B7B7B7",
"w  c #EDEDED",
"x  c #6D6D6D",
"y  c #101010",
"z  c #D0D0D0",
"A  c #070707",
"B  c #0C0C0C",
"C  c #0F0F0F",
"D  c #8F8F8F",
"E  c #313131",
"F  c #FEFEFE",
"G  c #919191",
"H  c #595959",
"I  c #EBEBEB",
"J  c #7B7B7B",
"K  c #4A4A4A",
"L  c #232323",
"M  c #2B2B2B",
"N  c #BEBEBE",
"O  c #AFAFAF",
"P  c #808080",
"Q  c #505050",
"R  c #ABABAB",
"S  c #474747",
"T  c #D4D4D4",
"U  c #878787",
"V  c #2C2C2C",
"W  c #FBFBFB",
"X  c #626262",
"Y  c #AAAAAA",
"Z  c #DCDCDC",
"`  c #F5F5F5",
" . c #ACACAC",
".. c #C1C1C1",
"+. c #5D5D5D",
"@. c #BABABA",
"#. c #B5B5B5",
"$. c #A7A7A7",
"%. c #5F5F5F",
"&. c #343434",
"*. c #202020",
"=. c #4B4B4B",
"-. c #767676",
";. c #A1A1A1",
">. c #080808",
",. c #060606",
"'. c #050505",
"). c #020202",
"!. c #010101",
"~. c #DDDDDD",
"{. c #A6A6A6",
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ",
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ",
". . . + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + . . . . ",
". . . @ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . $ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . $ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . % . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . & . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . * . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . * . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . = . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . - . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . - . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . ; . . . . . . . . . . . . . . . > , ' & ) ! , ~ { . . . . . . . . . . . . . . # + . . . . ",
". . . ] . . . . . . . . . . . . . ^ / + + + + + + + + ( _ . . . . . . . . . . . . . # + . . . . ",
". . . : . . . . . . . . . . . . < [ + + + + + + + + + + } | . . . . . . . . . . . . # + . . . . ",
". . . 1 . . . . . . . . . . . 2 3 + + + + + + + + + + + + 4 5 . . . . . . . . . . . # + . . . . ",
". . . 1 . . . . . . . . . . . 6 + + + + 7 8 9 0 9 a [ + + + b . . . . . . . . . . . # + . . . . ",
". . . c . . . . . . . . . . . d + + + + a . . . . . e + + + + f . . . . . . . . . . # + . . . . ",
". . . g . . . . . . . . . . . h + + + + i . . . . . j + + + + k . . . . . . . . . . # + . . . . ",
". . . l . . . . . . . . . . . m + + + + n . . . . . j + + + + o . . . . . . . . . . # + . . . . ",
". . . l . . . . . . . . . . . p + + + + 8 . . . . . q + + + + r . . . . . . . . . . # + . . . . ",
". . . s . . . . . . . . . . . , + + + + t u v w > x 7 + + + + ; . . . . . . . . . . # + . . . . ",
". . . y . . . . . . . . . . . z A + + + + + + + + + + + + + + B . . . . . . . . . . # + . . . . ",
". . . C . . . . . . . . . . . . D + + + + + + + + + + + + + + E . . . . . . . . . . # + . . . . ",
". . . C . . . . . . . . . . . . F G s + + + + + + + ' + + + + H . . . . . . . . . . # + . . . . ",
". . . ) . . . . . . . . . . . . . . I J K L [ M d N O + + + + P . . . . . . . . . . # + . . . . ",
". . . m . . . . . . . . . . . . . . . . . . . . . . Q + + + + R . . . . . . . . . . # + . . . . ",
". . . m . . . . . . . . . . . . S T . . . . . . . U + + + + V W . . . . . . . . . . # + . . . . ",
". . . t . . . . . . . . . . . . + 4 X Y Z ` <  .! + + + + + ... . . . . . . . . . . # + . . . . ",
". . . t . . . . . . . . . . . . + + + + + + + + + + + + + +.. . . . . . . . . . . . # + . . . . ",
". . . 7 . . . . . . . . . . . . + + + + + + + + + + + + o { . . . . . . . . . . . . # + . . . . ",
". . . [ . . . . . . . . . . . . @.E + + + + + + + + & #.. . . . . . . . . . . . . . # + . . . . ",
". . . [ . . . . . . . . . . . . . F $.%.&.B *.=.-.;.{ . . . . . . . . . . . . . . . # + . . . . ",
". . . >.. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . A . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . A . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . ,.. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . '.. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . } . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . } . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . 4 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . ).. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . # + . . . . ",
". . . !.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.{.+ . . . . ",
". . . + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + . . . . ",
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ",
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ",
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . "};
