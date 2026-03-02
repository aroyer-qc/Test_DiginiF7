//-------------------------------------------------------------------------------------------------
//
//  File :  label_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2020 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

// Notes some default label exist in the file "lib_label.h", some of them can be enable/disable in this configuration
#define     DIGINI_USE_LABEL_DATE                      DEF_ENABLED
#define     DIGINI_USE_LABEL_TIME                      DEF_ENABLED
#define     DIGINI_USE_LABEL_PRODUCT_INFO              DEF_ENABLED
#define     DIGINI_USE_LABEL_DECIMAL_KEY               DEF_ENABLED             // Enable label 0-9 and dot, del, sign, sign inversion
#define     DIGINI_USE_LABEL_HEXADECIMAL_KEY           DEF_ENABLED             // Enable label A-F

#define USER_LABEL_LANGUAGE_DEF(X_LABEL)  \
    X_LABEL( LBL_FIRMWARE_UPGRADE,       "Firmware Upgrade",                            "Mise \x85 Niveau Logiciel"                     ) \
    X_LABEL( LBL_SKIN_LOADING,           "Skin Loading        %%",                      "Th\x82matique          %%"                     ) \
    X_LABEL( LBL_SETTINGS,               "Settings",                                    "Configurations"                                ) \
    X_LABEL( LBL_PAGE_INFO,              "Software Information",                        "Information Logiciel"                          ) \
    X_LABEL( LBL_INFO,                   "Information",                                 nullptr                                         ) \
    X_LABEL( LBL_DIAG,                   "Diagnostic",                                  "Diagnostique"                                  ) \
    X_LABEL( LBL_TEST_1,                 "Float",                                       "Flottant"                                      ) \
    X_LABEL( LBL_TEST_2,                 "Decimal",                                     "D\x82" "cimale"                                ) \
    X_LABEL( LBL_TEST_3,                 "Hexa",                                        nullptr                                         ) \
    X_LABEL( LBL_TEST_4,                 "String",                                      nullptr                                         ) \

//-------------------------------------------------------------------------------------------------


//    X_LABEL(    LBL_AXIS,                   ASCII_DEVICE_CTRL2 "%3d.%04d",     ASCII_DEVICE_CTRL2 "%3d.%04d"        )
