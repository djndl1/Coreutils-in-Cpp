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
#include <cstddef>

#include <unistd.h>

using std::string;
using std::size_t;

class environment
{
    public:
        static environment& get_env();

        // these constructors and assignment operators are not needed for a singleton
        environment(const environment&) = delete;
        environment(environment&&) = delete;
        environment& operator=(const environment&) = delete;
        environment& operator=(environment&&) = delete;

    /* POSIX environmental variables */

        const string& pwd() const;
        string& pwd();

        const string& path() const;
        string& path();

        const string& home() const;
        string& home();

        const string& tmpdir() const;
        string& tmpdir();

        const string& tz() const;
        string& tz();

        const size_t columns() const;
        size_t& columns();
        
        const size_t lines() const;
        size_t& lines();

        const string& shell() const;
        string& shell();

        const string& term() const;
        string& term();

        const string& logname() const;
        string& logname();

        const string& lang() const;
        string& lang();

        const string& lc_all() const;
        string& lc_all();
        
        const string& lc_collate() const;
        string& lc_collate();

        const string& lc_ctype() const;
        string& lc_ctype();

        const string& lc_messages() const;
        string& lc_messages();

        const string& lc_monetary() const;
        string& lc_monetary();

        const string& lc_numeric() const;
        string& lc_numeric();

        const string& lc_time() const;
        string& lc_time();

        const string& nlspath() const;
        string& nlspath();

#ifdef _XOPEN_UNIX
        const string& msgverb() const;
        string& msgverb();

        const string& datemsk() const;
        string& datemsk();
#endif

    private:
        environment();

    /* POSIX environment variables 
     * for more information, see http://pubs.opengroup.org/onlinepubs/9699919799.2018edition/
     */
        string pwd;
        string path;
        string home;
        string tmpdir;
        string tz;          // timezone

        // terminal related
        size_t columns;     // terminal width
        size_t lines;       // terminal height
        string shell;
        string term;
        string logname;

        //internalization related
        string lang;
        string lc_all;
        string lc_collate;  // for collation
        string lc_ctype;    // character classification
        string lc_messages; // locale for messages
        string lc_monetary;
        string lc_numeric;
        string lc_time;     // date/time formatting
        string nlspath;

// if the system conforms to XSI
#ifdef _XOPEN_UNIX
        string msgverb;
        string datemsk;
#endif
}