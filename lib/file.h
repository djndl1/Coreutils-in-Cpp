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

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <algorithm>
#include <vector>
#include <string>
#include <cstddef>
#include <utility>
#include <ostream>
#include <ios>
#include <istream>

using std::size_t;


enum class seekdir_t
{
    FROM_BEGINNING = SEEK_SET,
    FROM_CURRENT   = SEEK_CUR,
    FROM_END       = SEEK_END
};

class file
{
public:
    using open_flags = int;
    using seek_dir = enum seekdir_t;
    using byte_buf = std::vector<unsigned char>;
    
    ~file();
    
    /**
     * __mode: 0442 default, do not use format like 0775 here, not gonna work
     */
    explicit
    file(const std::string pathname, const std::string flags, 
         const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    
    explicit
    file(const std::string pathname, const std::string flags, const std::string mode = "-rw-rw-r--");
    
    
    file(const file& file);
    
    file(file&& file);
    
    file&
    operator=(const file& rhs);
    
    file&
    operator=(file&& rhs);
    
    file&
    seek(off_t offset, seek_dir whence = seek_dir::FROM_BEGINNING);
    
    byte_buf&
    read(size_t nbytes);
    
    size_t
    write(byte_buf& buf, size_t nbytes);
    
    void
    sync(void);
    
    
private:
    int file_descriptor;
    std::string file_name;
    std::string file_pathname;
    
    open_flags file_flag;
    mode_t  file_mode;   
    
    off_t file_offset;
    
    char *file_buffer;
}
