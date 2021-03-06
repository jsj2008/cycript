/* Cycript - Optimizing JavaScript Compiler/Runtime
 * Copyright (C) 2009-2010  Jay Freeman (saurik)
*/

/* GNU Lesser General Public License, Version 3 {{{ */
/*
 * Cycript is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Cycript is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Cycript.  If not, see <http://www.gnu.org/licenses/>.
**/
/* }}} */

#ifndef SIG_FFI_TYPE_H
#define SIG_FFI_TYPE_H

#include <apr_pools.h>

#ifdef HAVE_FFI_FFI_H
#include <ffi/ffi.h>
#else
#include <ffi.h>
#endif

#include "sig/types.hpp"

namespace sig {

ffi_type *ObjectiveC(apr_pool_t *pool, struct Type *type);
ffi_type *Java(apr_pool_t *pool, struct Type *type);

void sig_ffi_cif(
    apr_pool_t *pool,
    ffi_type *(*sig_ffi_type)(apr_pool_t *, struct Type *),
    struct Signature *signature,
    ffi_cif *cif,
    size_t skip = 0,
    ffi_type **types = NULL,
    size_t offset = 0
);

void Copy(apr_pool_t *pool, ffi_type &lhs, ffi_type &rhs);

}

#endif/*SIG_FFI_TYPE_H*/
