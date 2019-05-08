/*
    Copyright (C) 2019 Hongzhi Deng 
    
    This file is part of Coreutils in C++.

    Coreutils in C++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Coreutils in C++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "environment.h"

#include <cstdlib>

using std::string;
using std::vector;

const vector<string> env_names = {
    "PWD",
    "PATH",
    "HOME",
    "TMPDIR",
    "TZ",
    "COLUMNS",
    "LINES",
    "SHELL",
    "TERM",
    "LOGNAME",
    "LANG",
    "LC_ALL",
    "LC_COLLATE",
    "LC_CTYPE",
    "LC_MESSAGE",
    "LC_MONETARY",
    "LC_NUMERIC",
    "LC_TIME",
    "NLSPTH",

#ifdef _XOPEN_UNIX
    "MSGVERB",
    "DATEMSK"
#endif
};




inline environment& 
environment::access_env()
{
    static environment env_instance{};

}