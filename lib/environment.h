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

#pragma once

#include <cstddef>
#include <vector>

class std::string;

using std::size_t;

class environment
{
    public:
        static environment& access_env();

        // these constructors and assignment operators are not needed for a singleton
        environment(const environment&) = delete;
        environment(environment&&) = delete;
        environment& operator=(const environment&) = delete;
        environment& operator=(environment&&) = delete;

    /* POSIX environmental variables */

        const std::string& pwd() const;
        void set_pwd(std::string&);

        const std::string& path() const;
        void set_path(std::string&);

        const std::string& home() const;
        void set_home(std::string&);

        const std::string& tmpdir() const;
        void set_tmpdir(std::string&);

        const std::string& tz() const;
        void set_tz(std::string&);

        const size_t columns() const;
        void set_columns(std::string&);
        
        const size_t lines() const;
        void set_lines(std::string&);

        const std::string& shell() const;
        void set_shell(std::string&);

        const std::string& term() const;
        void set_term(std::string&);

        const std::string& logname() const;
        void set_logname(std::string&);

        const std::string& lang() const;
        void set_lang(std::string&);

        const std::string& lc_all() const;
        void set_lc_all(std::string&);
        
        const std::string& lc_collate() const;
        void set_lc_ctype(std::string&);

        const std::string& lc_ctype() const;
        void set_lc_ctype(std::string&);

        const std::string& lc_messages() const;
        void set_lc_messages(std::string&);

        const std::string& lc_monetary() const;
        void set_lc_monetary(std::string&);

        const std::string& lc_numeric() const;
        void set_lc_numeric(std::string&);

        const std::string& lc_time() const;
        void set_lc_time(std::string&);

        const std::string& nlspath() const;
        void set_nlspath(std::string&);

#ifdef _XOPEN_UNIX
        const std::string& msgverb() const;
        void set_msgverb(std::string&);

        const std::string& datemsk() const;
        void set_datemsk(std::string&);
#endif

    private:
        environment();

    /* POSIX environment variables 
     * for more information, see http://pubs.opengroup.org/onlinepubs/9699919799.2018edition/
     */
        std::string pwd;
        std::string path;
        std::string home;
        std::string tmpdir;
        std::string tz;          // timezone

        // terminal related
        size_t columns;     // terminal width
        size_t lines;       // terminal height
        std::string shell;
        std::string term;
        std::string logname;

        //internalization related
        std::string lang;
        std::string lc_all;
        std::string lc_collate;  // for collation
        std::string lc_ctype;    // character classification
        std::string lc_messages; // locale for messages
        std::string lc_monetary;
        std::string lc_numeric;
        std::string lc_time;     // date/time formatting
        std::string nlspath;

// if the system conforms to XSI
#ifdef _XOPEN_UNIX
        std::string msgverb;
        std::string datemsk;
#endif

        const 
}