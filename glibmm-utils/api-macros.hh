/* -*- Mode: C++; indent-tabs-mode:nil; c-basic-offset:4; -*- */

/*
 *  glibmm-utils - api-macros.hh
 *
 *  Copyright (C) 2007 Marko Anastasov
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __GLIBMM_UTILS_API_MACROS_HH__
#define __GLIBMM_UTILS_API_MACROS_HH__

/*
 * Usage examples:
 *
 * class GTKMM_UTILS_API MyClass
 * {
 *     ...
 * };
 *
 * bool GTKMM_UTILS_API free_falling_function(void);
 *
 * For an exception type that may be thrown across a DSO boundary, you must use:
 *
 * class GTKMM_UTILS_EXCEPTION_API MyException
 * {
 *     ...
 * };
 *
 * For information on the gcc visibility support see:
 *     http://gcc.gnu.org/wiki/Visibility
 *     http://people.redhat.com/drepper/dsohowto.pdf
 *
 */

#ifdef HAVE_GCC_SYMBOL_VISIBILITY
    /* Forces inclusion of a symbol in the symbol table, so
     * software outside the library can use it.
     */
    #define GTKMM_UTILS_API __attribute__ ((visibility("default")))

    // Forces a symbol to be private to the library / app.
    #define GTKMM_UTILS_LOCAL __attribute__ ((visibility("hidden")))
#else
    #define GTKMM_UTILS_API
    #define GTKMM_UTILS_LOCAL
#endif

#ifndef GTKMM_UTILS_EXCEPTION_API
    #define GTKMM_UTILS_EXCEPTION_API GTKMM_UTILS_API
#endif

#endif // __GLIBMM_UTILS_API_MACROS_HH__
