/*
    Copyright (C) 2019 Hongzhi Deng 
    
    This file is part of Coreutils in C++.

    Coreutils in C++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>

using std::string;

class environment
{
    public:
        static environment& get_env();

        // these constructors and assignment operators are not needed for a singleton
        environment(const environment&) = delete;
        environment(environment&&) = delete;
        environment& operator=(const environment&) = delete;
        environment& operator=(environment&&) = delete;

        // POSIX.1
        const string& get_pwd() const;

        const string& get_path() const;
    private:
        environment();


        //environment variables
        string pwd;
        string path;
}