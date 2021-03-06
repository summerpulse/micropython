/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Paul Sokolovsky
 * Copyright (c) 2015 Daniel Campora
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mpconfig.h"
#include MICROPY_HAL_H
#include "py/nlr.h"
#include "py/runtime.h"
#include "py/binary.h"
#include "extmod/modubinascii.h"
#include "modubinascii.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_dthe.h"
#include "hw_memmap.h"
#include "rom_map.h"
#include "prcm.h"
#include "crc.h"
#include "cryptohash.h"
#include "mpexception.h"


/******************************************************************************/
// Micro Python bindings

STATIC const mp_map_elem_t mp_module_binascii_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__),        MP_OBJ_NEW_QSTR(MP_QSTR_ubinascii) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_hexlify),         (mp_obj_t)&mod_binascii_hexlify_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_unhexlify),       (mp_obj_t)&mod_binascii_unhexlify_obj },
};

STATIC MP_DEFINE_CONST_DICT(mp_module_binascii_globals, mp_module_binascii_globals_table);

const mp_obj_module_t mp_module_ubinascii = {
    .base = { &mp_type_module },
    .name = MP_QSTR_ubinascii,
    .globals = (mp_obj_dict_t*)&mp_module_binascii_globals,
};
