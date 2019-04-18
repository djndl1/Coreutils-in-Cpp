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

#include "limits_wrapper.h"
#include "sys_error.h"
#include "file_stat.h"
#include "environment.h"
#include <string>

#include <unistd.h>
#include <errno.h>
#include <vector>


using std::string;
using std::vector;
using std::out_of_range;

string cxx_getcwd(void)
{
    char cwd[limits_wrapper::path_max()];

    char *result = getcwd(cwd, limits_wrapper::path_max());
    if (result == NULL && errno != 0)
        throw sys_error(errno);

    return cwd;
}

string pwd(vector<string> args)
{
    string pwd = cxx_getcwd();
    string pwd_env = environment::get_env().get_pwd();

    // if logical path is pecified "-P"
    bool logical_flag = true;
    for (auto& arg : args) {
        if (arg == "-P")
            logical_flag = false;
        else if (arg == "-L")
            logical_flag = true;
    }

    if (pwd_env.size() == 0 || pwd_env.size() > limits_wrapper::path_max())
        pwd_env = pwd;

    return (logical_flag == true) ? pwd_env : pwd;
}