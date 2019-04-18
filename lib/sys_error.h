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

#include <stdexcept>

#include <cerrno>
#include <cstring> 

class sys_error : public std::exception
{
    public:
        sys_error(int errnum = 0);

        const char* what() const noexcept;

        const int errnum() const;

        int& errnum();
    private:
        int error_number;
}

inline sys_error::sys_error(int errnum)
{
    error_number = errnum;
}

inline const char* 
sys_error::what() noexcept
{
    return strerror(error_number);
}

inline const int
sys_error::errnum() const
{
    return error_number;
}

inline int&
sys_error::errnum()
{
    return error_number;
}