//-------------------------------------------------------------------------------------------------
//
//  File :  widget_cfg.h
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
//
//  Notes:
//
//  Px      -> Position X
//  Py      -> Position Y
//  Px1-Px4 -> Position Point X
//  Py1-Py4 -> Position Point Y
//  Sx      -> Size X
//  Sy      -> Size Y
//  TPx     -> Text Position X
//  TPy     -> Text Position Y
//  TSx     -> Text Size X
//  TSy     -> Text Size Y
//  GPx     -> Glyph Position X
//  GPy     -> Glyph Position Y
//  BC      -> Back Color
//  TC      -> Text Color
//  TAC     -> Text Alternate Color
//  TAC2    -> Text Alternate Color 2
//  TC_PR   -> Text Color for pressed button
//  TC_GR   -> Text Color for inactive button
//  PTC     -> Pressed Text Color
//  TOPx    -> Touch Position X
//  TOPy    -> Touch Position Y
//  TOSx    -> Touch Size X
//  TOSy    -> Touch Size Y
//  COx     -> Cursor Offset X
//  COy     -> Cursor Offset Y
//  CSV     -> Cursor Start Value      ex. 0%
//  CEV     -> Cursor End Value        ex. 100%
//  CPR     -> Cursor Pixel Range      ex. 0% to 100% = 384 Pixel
//  ResX    -> Resolution Widget X     Not necessarily in pixel ( Ex. SPECTRUM -> 16 line x 12 dot)
//  ResY    -> Resolution Widget Y
//
//
//-------------------------------------------------------------------------------------------------
//
//  'Timing' is for future development, so we can decide to refresh widget at different interval
//                  GRAFX_OPTION_MOVABLE_OBJECT future development
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Individual Exchange Data Definition
//-------------------------------------------------------------------------------------------------

//           Enum ID,           Struct Ptr
// This X-Macro build a list of struct pointer to exchange data between page and/or application service.
// Note(s) First data of every exchange data structure is always ExchangeType_e. So Button can use this exchange system and able to print label into button
#define XCHANGE_DEF(X_XCHANGE) \
 X_XCHANGE ( CFG_INPUT_10_D,    &Input10_D_Cfg)         \
 X_XCHANGE ( CFG_INPUT_6_D,     &Input6_D_Cfg)          \
 X_XCHANGE ( CFG_INPUT_5_D,     &Input5_D_Cfg)          \

//-------------------------------------------------------------------------------------------------
// Individual widget Definition
//-------------------------------------------------------------------------------------------------
//       Enum ID,         Service,      Sub, Px, Py, IMG0,             IMG_1,         IMG_2,         IMG_3,         IMG_4,         IMG_5,         IMG_6,         IMG_7,         IMG_8,         IMG_9,         IMG_10,        IMG_11,        IMG_12,        IMG_13,        IMG_14,        IMG_15,        Options
#define BACK_DEF(X_BACK)\
 X_BACK( BACK_LOADING,    SERV_ID_RFSH, 0,   0,  0,  LOADING_BACK,     INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE )\
 X_BACK( BACK_DIAMOND,    SERV_ID_RFSH, 0,   0,  0,  BG_IMG,           INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, INVALID_IMAGE, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE )\

//      Enum ID,           Service,      Sub,                   Px,   Py,   Released btn,   Pressed button,         Inactive button,   GPx,  GPy,  Released glyph,     Pressed glyph,      Inactive glyph  TOPx, TOPy, TOSx, TOSy, TPx,  TPy,    TSx,  TSy,  TC,         TC_PR,        TC_GR,        Font ID,          Text Option,             Text Label,     Filter,                 Option,
#define BTN_DEF(X_BTN) \
 X_BTN( BTN_SETTING,       SERV_ID_BDEF, SLIDING_RIGHT_OVLAP,   426,  10,   BT_SPHERE,      BT_SPHERE_PR,           INVALID_IMAGE,     8,    8,    GL_TOOLS,           GL_TOOLS,           INVALID_IMAGE,  426,  10,   45,   45,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 /*X_BTN( BTN_JOG,           SERV_ID_BDEF, 0,                   426,  40,   BT_SPHERE,      BT_SPHERE_PR,           INVALID_IMAGE,     8,    8,    GL_JOG,             GL_JOG,             INVALID_IMAGE,  426,  10,   45,   45,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)*/\
 X_BTN( BTN_RETURN,        SERV_ID_BDEF, SLIDING_LEFT_DE_OVLAP, 426,  10,   BT_SPHERE,      BT_SPHERE_PR,           INVALID_IMAGE,     8,    8,    GL_RETURN,          GL_RETURN,          INVALID_IMAGE,  426,  10,   45,   45,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_RETURN_DOWN,   SERV_ID_BDEF, SLIDING_DOWN,          426,  10,   BT_SPHERE,      BT_SPHERE_PR,           INVALID_IMAGE,     8,    8,    GL_RETURN,          GL_RETURN,          INVALID_IMAGE,  426,  10,   45,   45,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 /* Keypad input value */ \
 X_BTN( BTN_1,             SERV_ID_INPT, '1',                   10,   107,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  10,   107,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_1,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_2,             SERV_ID_INPT, '2',                   90,   107,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  90,   107,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_2,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_3,             SERV_ID_INPT, '3',                   170,  107,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  170,  107,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_3,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_4,             SERV_ID_INPT, '4',                   10,   149,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  10,   149,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_4,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_5,             SERV_ID_INPT, '5',                   90,   149,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  90,   149,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_5,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_6,             SERV_ID_INPT, '6',                   170,  149,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  170,  149,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_6,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_7,             SERV_ID_INPT, '7',                   10,   191,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  10,   191,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_7,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_8,             SERV_ID_INPT, '8',                   90,   191,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  90,   191,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_8,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_9,             SERV_ID_INPT, '9',                   170,  191,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  170,  191,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_9,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_TOGGLE_SIGN,   SERV_ID_INPT, '±',                   10,   233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      BT_YELLOW_LONG_GR, 0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  10,   233,  75,   38,   18,    6,     40,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_TOGGLE_SIGN,SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_0,             SERV_ID_INPT, '0',                   90,   233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  90,   233,  75,   38,   27,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_DIGITAL_24,    _X_CENTER_Y_CENTER,      LBL_0,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_DOT,           SERV_ID_INPT, '.',                   170,  233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      BT_YELLOW_LONG_GR, 0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  170,  233,  75,   38,   32,    10,    8,    8,    GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_24,      _X_CENTER_Y_CENTER,      LBL_DOT,        SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_A,             SERV_ID_INPT, 'A',                   10,   233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  10,   233,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_A,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_B,             SERV_ID_INPT, 'b',                   170,  233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  170,  233,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_B,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_C,             SERV_ID_INPT, 'C',                   250,  233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  250,  233,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_C,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_D,             SERV_ID_INPT, 'd',                   250,  191,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  250,  191,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_D,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_E,             SERV_ID_INPT, 'E',                   250,  149,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  250,  149,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_E,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_F,             SERV_ID_INPT, 'F',                   250,  107,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  250,  107,  75,   38,   28,    7,     20,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_F,          SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_DEL,           SERV_ID_INPT, '<',                   400,  149,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      BT_YELLOW_LONG_GR, 0,    0,    INVALID_IMAGE,      INVALID_IMAGE,      INVALID_IMAGE,  400,  149,  75,   38,   10,    7,     60,   26,   GRAY_28,    GRAY_20,      GRAY_16,      FT_ARIAL_16,      _X_CENTER_Y_CENTER,      LBL_DEL,        SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_OK,            SERV_ID_INPT, '@',                   400,  191,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      BT_YELLOW_LONG_GR, 23,   4,    GL_OK,              GL_OK,              GL_OK_GR,       400,  191,  75,   38,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_CANCEL,        SERV_ID_INPT, '!',                   400,  233,  BT_YELLOW_LONG, BT_YELLOW_LONG_PR,      INVALID_IMAGE,     21,   4,    GL_CANCEL,          GL_CANCEL,          INVALID_IMAGE,  400,  233,  75,   38,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_DIAG,          SERV_ID_BDEF, SLIDING_UP,            281,  170,  BT_MENU,        BT_MENU_PR,             BT_MENU_GR,        126,  12,   GL_DIAG,            GL_DIAG,            INVALID_IMAGE,  281,  170,  158,  45,   12,    13,    100,  12,   BROWN,      BLACK,        0,            FT_ARIAL_10,      0,                       LBL_DIAG,       SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_INFO,          SERV_ID_BDEF, SLIDING_UP,            281,  220,  BT_MENU,        BT_MENU_PR,             BT_MENU_GR,        126,  12,   GL_INFO,            GL_INFO,            INVALID_IMAGE,  281,  220,  158,  45,   12,    13,    100,  12,   BROWN,      BLACK,        0,            FT_ARIAL_10,      0,                       LBL_INFO,       SERVICE_FILTER_NORMAL,  GRAFX_OPTION_TOUCH_RECTANGLE)\
/* Spindle page */ \
 X_BTN( BTN_DOWN_MIN,      SERV_ID_SPIN, 3,                     22,   220,  GL_CHECK_BOX,   GL_CHECK_BOX_PR,        GL_CHECK_BOX_GR,   5,    6,    GL_DOWN,            GL_DOWN,            INVALID_IMAGE,  22,    220, 40,   40,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL_AND_TYPEMATIC,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_UP_MIN,        SERV_ID_SPIN, 4,                     192,  220,  GL_CHECK_BOX,   GL_CHECK_BOX_PR,        GL_CHECK_BOX_GR,   5,    5,    GL_UP,              GL_UP,              INVALID_IMAGE,  192,   220, 40,   40,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL_AND_TYPEMATIC,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_DOWN_MAX,      SERV_ID_SPIN, 5,                     242,  220,  GL_CHECK_BOX,   GL_CHECK_BOX_PR,        GL_CHECK_BOX_GR,   5,    6,    GL_DOWN,            GL_DOWN,            INVALID_IMAGE,  242,   220, 40,   40,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL_AND_TYPEMATIC,  GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_BTN( BTN_UP_MAX,        SERV_ID_SPIN, 6,                     412,  220,  GL_CHECK_BOX,   GL_CHECK_BOX_PR,        GL_CHECK_BOX_GR,   5,    5,    GL_UP,              GL_UP,              INVALID_IMAGE,  412,   220, 40,   40,   0,     0,     0,    0,    0,          0,            0,            INVALID_FONT,     0,                       INVALID_LABEL,  SERVICE_FILTER_NORMAL_AND_TYPEMATIC,  GRAFX_OPTION_TOUCH_RECTANGLE)\

//            Enum ID,      Service,       Sub, Px,   Py,   Sx,   Sy,   Top Left,    Top Right,    Bottom Left,    Bottom Right,    Horizontal,    Vertical     Filter                 Option
#define BASIC_BOX_DEF(X_BASIC_BOX) \
 X_BASIC_BOX( BOX_T,        SERV_ID_RFSH,  0,   176,  0,    240,  272,  GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_AXIS,     SERV_ID_RFSH,  0,   0,    0,    480,  272,  GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_BASIC_BOX( BOX_EDIT,     SERV_ID_RFSH,  0,   10,   36,   460,  60,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
/* XY or ZX Display Page */ \
 X_BASIC_BOX( BOX_1_3,      SERV_ID_BDEF,  0,   0,    0,    400,  88,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_2_3,      SERV_ID_BDEF,  0,   0,    91,   400,  88,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_3_3,      SERV_ID_BDEF,  0,   0,    183,  400,  89,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
/* XYZ Display Page */ \
 X_BASIC_BOX( BOX_1_4,      SERV_ID_BDEF,  0,   0,    0,    400,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_2_4,      SERV_ID_BDEF,  0,   0,    69,   400,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_3_4,      SERV_ID_BDEF,  0,   0,    138,  400,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_4_4,      SERV_ID_BDEF,  0,   0,    207,  400,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
/* XYT Display Page */ \
 X_BASIC_BOX( BOX_1_3T,     SERV_ID_BDEF,  0,   0,    0,    174,  88,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_2_3T,     SERV_ID_BDEF,  0,   0,    91,   174,  88,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_3_3T,     SERV_ID_BDEF,  0,   0,    183,  174,  89,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
/* XYZT Display Page */ \
 X_BASIC_BOX( BOX_1_4T,     SERV_ID_BDEF,  0,   0,    0,    174,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_2_4T,     SERV_ID_BDEF,  0,   0,    69,   174,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_3_4T,     SERV_ID_BDEF,  0,   0,    138,  174,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\
 X_BASIC_BOX( BOX_4_4T,     SERV_ID_BDEF,  0,   0,    207,  174,  65,   GL_TOP_LEFT, GL_TOP_RIGHT, GL_BOTTOM_LEFT, GL_BOTTOM_RIGHT, GL_HORIZONTAL, GL_VERTICAL, SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE | GRAFX_OPTION_DRAW_ONCE)\

#define GRAPH_DEF(X_GRAPH) \
 X_GRAPH( GRAPH_TEST_T,     SERV_ID_RFSH,  0,   100,  10,   240,  110, LIGHT_GREEN, 20,     20,     200,     100,     2,      199,    GRAFX_OPTION_TOUCH_RECTANGLE)\

//            Enum ID,      Type,           Px1,   Py1,   Px2,   Py2,   Px3,   Py3,   Px4,   Py4,  Color,       Thickness,  Options
#define BASIC_SHAPE_DEF(X_BASIC_SHAPE) \
 X_BASIC_SHAPE( LINE_TITLE, BASIC_LINE,     10,    34,    470,   34,    0,     0,     0,     0,    GREEN,       2,          GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\

//      Enum ID,                 Service,      Sub, Px,   Py,   Sx,   Sy,   TC,          TAC,         TAC2,    Font ID,        Text Blend,   Text Label             Text Option         Option
#define LABEL_DEF(X_LBL) \
 X_LBL( LABEL_TIME,              SERV_ID_TIME, 0,   20,   7,    200,  16,   WHITE,       GREEN,       0,       SYS_FT_16,      CLEAR_BLEND,  LBL_TIME,              _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE)\
 X_LBL( LABEL_DATE,              SERV_ID_DATE, 0,   20,   67,   200,  16,   WHITE,       GREEN,       0,       SYS_FT_16,      CLEAR_BLEND,  LBL_DATE,              _X_LEFT_Y_CENTER,   GRAFX_OPTION_NONE)\
 X_LBL( LABEL_SKIN_LOADING,      SERV_ID_SKLD, 0,   134,  222,  300,  16,   GRAY_16,     GRAY_16,     GRAY_16, SYS_FT_16,      CLEAR_BLEND,  LBL_SKIN_LOADING,      _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE)\
 X_LBL( LABEL_PRINT_NUMBER,      SERV_ID_INPT, 'P', 16,   48,   448,  36,   GRAY_28,     RED,         0,       FT_DIGITAL_36,  CLEAR_BLEND,  LBL_STRING,            _X_RIGHT_Y_CENTER,  GRAFX_OPTION_NONE)\
 X_LBL( LABEL_INPT_TITLE,        SERV_ID_INPT, 'L', 16,   2,    448,  16,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_CENTER_Y_CENTER, GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
/* XY XZ XYZ XYZA Display Page */ \
 X_LBL( LABEL_PAGE_MAIN_MENU,    SERV_ID_RFSH, 0,   20,   10,   200,  24,   GRAY_28,     0,           0,       FT_ARIAL_24,    ALPHA_BLEND,  LBL_MAIN_MENU,         _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
/* Information Page */ \
 X_LBL( LABEL_INFO,              SERV_ID_RFSH, 0,   10,   20,   200,  10,   GRAY_28,     0,           0,       FT_ARIAL_24,    ALPHA_BLEND,  LBL_PAGE_INFO,         _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_FW_NAME_INFO,      SERV_ID_RFSH, 0,   10,   60,   200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_FW_NAME_INFO,      _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_FW_VERSION_INFO,   SERV_ID_RFSH, 0,   10,   90,   200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_FW_VERSION_INFO,   _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_GUI_NAME_INFO,     SERV_ID_RFSH, 0,   10,   120,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_GUI_NAME_INFO,     _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_GUI_VERSION_INFO,  SERV_ID_RFSH, 0,   10,   150,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_GUI_VERSION_INFO,  _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_HARDWARE_INFO,     SERV_ID_RFSH, 0,   10,   180,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_HARDWARE_INFO,     _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_SERIAL_INFO,       SERV_ID_RFSH, 0,   10,   210,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_SERIAL_INFO,       _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_COMPILE_DATE_INFO, SERV_ID_RFSH, 0,   10,   240,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_COMPILE_DATE_INFO, _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_FIRMWARE,     SERV_ID_INFO, 0,   200,  60,   200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_VERSION,      SERV_ID_INFO, 1,   200,  90,   200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_GUI_FIRMWARE, SERV_ID_INFO, 2,   200,  120,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_GUI_VERSION,  SERV_ID_INFO, 3,   200,  150,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_HARDWARE,     SERV_ID_INFO, 4,   200,  180,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_SERIAL,       SERV_ID_INFO, 5,   200,  210,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\
 X_LBL( LABEL_INFO_DATE,         SERV_ID_INFO, 6,   200,  240,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_16,    ALPHA_BLEND,  LBL_STRING,            _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE)\


//X_LBL(   LABEL_SAFETY_DOOR,     SERV_ID_RFSH, 0,   270,  190,  200,  10,   GRAY_28,     0,           0,       FT_ARIAL_10,    ALPHA_BLEND,  LBL_INPUT_DOOR,   _X_LEFT_Y_CENTER,   GRAFX_OPTION_DRAW_ONCE_AND_REMOVE | GRAFX_OPTION_DRAW_ON_BACK)

//             Enum ID,                 Service,      Sub, Px,   Py,   Sx,   Sy,   TC,         TAC,       TAC2,        Font ID,        Text Blend,  State 0,          State 1,            State 2,       State 3,        Text Option,       Option
//#define LABEL_LIST_DEF(X_LABEL_LIST)

//           Enum ID,            Service,      Sub, Px,  Py,  Sx,  Sy,  Background IMG, Bar IMG        Cursor Image,     COx,  COy,  CSV,  CEV,  CPR,  TPx,  TPy,  TSx,  TSy,  TC,      TAC,     TAC2,     Font ID,   Text Option,         Text Label,        Option
#define PROGRESS_DEF(X_PROGRESS) \
 X_PROGRESS( PROGRESS_LOADING,   SERV_ID_SKLD, 2,   25,  159, 430, 43,  INVALID_IMAGE,  LOADING_BAR,   LOADING_CURSOR,   20,   13,   0,    100,  384,  260,  63,   48,   16,   GRAY_16, GRAY_16, GRAY_16,  SYS_FT_16, _X_CENTER_Y_CENTER,  LBL_PERCENT,       GRAFX_OPTION_ORIENTATION_HORIZONTAL | GRAFX_OPTION_BLEND_CLEAR)\

// TODO change... and dont use hub for single link ( all widget can return a new link...
//      Enum ID,                Service,        Sub, LinkList
#define VIRTUAL_HUB_DEF(X_HUB) \
 X_HUB( VIRTUAL_MAIN_HUB,       SERV_ID_MHUB,   0,   LINK_LIST_MAIN_HUB )\
/* X_HUB( VIRTUAL_JOG_HUB,       SERV_ID_JHUB,   0,   LINK_LIST_JOG_HUB )*/\

//       Enum ID,               Service,      Sub, Px,  Py,       Sx,   Sy,  Icon 0,           Icon 1,          Icon 2,        Icon 3,            Option,
#define ICON_DEF(X_ICON) \
 X_ICON( ICON_LED_SPINDLE_3_3,  SERV_ID_ENBL, 9,   140, 212,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_BLEND_CLEAR )\
 X_ICON( ICON_LED_SPINDLE_4_4,  SERV_ID_ENBL, 9,   180, 225,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_BLEND_CLEAR )\
 X_ICON( ICON_LED_LIMIT_X_3,    SERV_ID_INPU, 0,   90,  11,       0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_X_4,    SERV_ID_INPU, 0,   90,  15,       0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_X_3T,   SERV_ID_INPU, 0,   6,   60,       0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_X_4T,   SERV_ID_INPU, 0,   10,  38,       0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y_3,    SERV_ID_INPU, 1,   90,  101,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y_4,    SERV_ID_INPU, 1,   90,  83,       0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y_3T,   SERV_ID_INPU, 1,   6,   151,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y_4T,   SERV_ID_INPU, 1,   10,  107,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z_3,    SERV_ID_INPU, 2,   90,  101,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z_4,    SERV_ID_INPU, 2,   90,  151,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z_3T,   SERV_ID_INPU, 2,   6,   151,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z_4T,   SERV_ID_INPU, 2,   10,  176,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
/* XYT or ZXT Display Pages */ \
 X_ICON( ICON_LED_SPINDLE_3_3T, SERV_ID_ENBL, 9,   20, 212,       0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_BLEND_CLEAR )\
/* XYZT Display Pages */ \
 X_ICON( ICON_LED_SPINDLE_4_4T, SERV_ID_ENBL, 9,   20,  240,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_BLEND_CLEAR )\
/* All icon machine are draw on top of each other, so first one will erase area, all other are merge, single draw until ask to be redraw with service SERVICE_REDRAW */\
 X_ICON( ICON_MACHINE_XY,       SERV_ID_MACH, 20,  18,  80 + 57,  0,    0,   INVALID_IMAGE,    GL_XY,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_ZX,       SERV_ID_MACH, 21,  18,  80 + 50,  0,    0,   INVALID_IMAGE,    GL_ZX,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_Z,        SERV_ID_MACH, 22,  18,  80,       0,    0,   INVALID_IMAGE,    GL_Z,            INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_A,        SERV_ID_MACH, 23,  42,  80 + 101, 0,    0,   INVALID_IMAGE,    GL_A,            INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_B,        SERV_ID_MACH, 24,  60,  80 + 67,  0,    0,   INVALID_IMAGE,    GL_B,            INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_C,        SERV_ID_MACH, 25,  10,  80 + 35,  0,    0,   INVALID_IMAGE,    GL_C,            INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_A2,       SERV_ID_MACH, 26,  60,  80 + 67,  0,    0,   INVALID_IMAGE,    GL_A2,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_MACHINE_C2,       SERV_ID_MACH, 27,  41,  80 + 101, 0,    0,   INVALID_IMAGE,    GL_C2,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
/* Icon leds for diagnostic page */\
 X_ICON( ICON_LED_LIMIT_X1,     SERV_ID_INPU, 0,   10,  60,       0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y1,     SERV_ID_INPU, 1,   10,  100,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z1,     SERV_ID_INPU, 2,   10,  140,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_A1,     SERV_ID_INPU, 3,   240, 60,       0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_B1,     SERV_ID_INPU, 4,   240, 100,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_C1,     SERV_ID_INPU, 5,   240, 140,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_X2,     SERV_ID_INPU, 6,   34,  60,       0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y2,     SERV_ID_INPU, 7,   34,  100,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z2,     SERV_ID_INPU, 8,   34,  140,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_A2,     SERV_ID_INPU, 9,   264, 60,       0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_B2,     SERV_ID_INPU, 10,  264, 100,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_C2,     SERV_ID_INPU, 11,  264, 140,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_ABORT,        SERV_ID_INPU, 12,  10,  180,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_RESUME,       SERV_ID_INPU, 13,  240, 180,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_HOLD,         SERV_ID_INPU, 14,  10,  220,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_PROBE,        SERV_ID_INPU, 15,  240, 220,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
/* Check box and hook for machine selection page */\
 X_ICON( ICON_XY_MAC,           SERV_ID_RFSH, 0,   140,  70,      40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_ZX_MAC,           SERV_ID_RFSH, 0,   140,  120,     40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_XYZ_MAC,          SERV_ID_RFSH, 0,   140,  170,     40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_A_MAC,            SERV_ID_RFSH, 0,   310,  70,      40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_B_MAC,            SERV_ID_RFSH, 0,   310,  120,     40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_C_MAC,            SERV_ID_RFSH, 0,   310,  170,     40,   40,  GL_CHECK_BOX,     INVALID_IMAGE,   INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_CLEAR )\
 X_ICON( ICON_CHECK_XY,         SERV_ID_MACH, 10,  146,  70,      0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_CHECK_ZX,         SERV_ID_MACH, 11,  146,  120,     0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_CHECK_XYZ,        SERV_ID_MACH, 12,  146,  170,     0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_CHECK_A,          SERV_ID_MACH, 13,  316,  70,      0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_CHECK_B,          SERV_ID_MACH, 14,  316,  120,     0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_CHECK_C,          SERV_ID_MACH, 15,  316,  170,     0,    0,   INVALID_IMAGE,    GL_OK,           INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_ENABLE,       SERV_ID_RFSH, 0,   440,  100,     0,    0,   GL_LED_RED_OFF,   GL_LED_RED_ON,   GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_COOLANT,      SERV_ID_RFSH, 0,   440,  160,     0,    0,   GL_LED_RED_OFF,   GL_LED_RED_ON,   GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_MIST,         SERV_ID_RFSH, 0,   440,  220,     0,    0,   GL_LED_RED_OFF,   GL_LED_RED_ON,   GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
/* LED limit for Pages AXIS */\
 X_ICON( ICON_LED_LIMIT_X_AXIS, SERV_ID_INPU, 0,   200,  30,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Y_AXIS, SERV_ID_INPU, 1,   200,  30,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
 X_ICON( ICON_LED_LIMIT_Z_AXIS, SERV_ID_INPU, 2,   200,  30,      0,    0,   GL_LED_RED_ON,    GL_LED_RED_OFF,  GL_LED_GRAY_OFF,  INVALID_IMAGE,  GRAFX_OPTION_NONE )\
/* Spindle Page */\
 X_ICON( ICON_LED_SPINDLE,      SERV_ID_ENBL, 9,   90,   86,      0,    0,   GL_LED_GREEN_OFF, GL_LED_GREEN_ON, INVALID_IMAGE,    INVALID_IMAGE,  GRAFX_OPTION_BLEND_CLEAR )\

//             Enum ID,               Service,      Sub, Px,  Py,  Sx,  Sy,  Color,    Filter,                 Options
#define BASIC_RECT_DEF(X_BASIC_RECT) \
 X_BASIC_RECT( RECT_BLANK_MACHINE,    SERV_ID_RFSH, 0,   10,  80,  120, 150, BLACK,    SERVICE_FILTER_NORMAL,  GRAFX_OPTION_NONE   ) \

//            Enum ID,          Service,       Sub, Px,  Py,  Sx,  Sy,  TC,          Font ID,      Filter,                Options
#define TERMINAL_DEF(X_TERMINAL) \
 X_TERMINAL ( TERM_GCODE,       SERV_ID_GCOD,  0,   182, 5,   228, 262, LIGHT_GREEN, FT_TERMINAL,  SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE)\
 X_TERMINAL ( TERM_GCODE_FULL,  SERV_ID_GCOD,  1,   0,   0,   430, 272, LIGHT_GREEN, FT_ARIAL_10,  SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE)\

//              Enum ID,         Service,       Sub, Timing, Px,  Py,  Sx,  Sy,  Slide Direction,         Filter,                Options

#if 0

// Kept for reference

#define PAGE_SLIDE_DEF(X_PAGE_SLIDE) \
 X_PAGE_SLIDE ( PS_MAIN_AXIS_X,  SERV_ID_NONE,  0,   182, 5,   228, 262, SLIDING_LEFT_AND_RIGHT,  SERVICE_FILTER_NORMAL, GRAFX_OPTION_TOUCH_RECTANGLE)\

//                                                Enum ID,                Service,         SubService,  Pos X,  Pos Y,  Size X,  Size Y,  Thickness,  Back Color,  Press Back Color,  Box Color,   Press Box Color,  Text PosX,  Text PosY,  Text Size X,  Text Size Y,  Text Color,  pressed Text Color,  Font ID,         Text Option,              Text Label,  Filter
#define BASIC_BTN_DEF(X_BASIC_BTN)  X_BASIC_BTN(  BASIC_BUTTON_OK,        SERV_ID_BDEF,    0,           400,    100,    78,      32,      3,          BLACK,       WHITE,             RED,          GREEN,           10,         7,          60,           20,           WHITE,       GRAY_16,             SYS_FT_16,  _X_CENTER_Y_CENTER,  LBL_OK,      SERVICE_FILTER_NORMAL  )\


//                                                Enum ID,                Service,         SubService,  Pos X,  Pos Y,  Gif
#define GIF_DEF(X_GIF)         X_GIF(             ICON_GIF,               SERV_ID_RFSH,    0,           30,     2,      INVALID_IMAGE )\

//                                                Enum ID,                Service,         SubService,  Pos X,  Pos Y,  Gif
#define GRAPH_DEF(X_GGRAPH)       X_GGRAPH(       GRAPH_TEST,             SERV_ID_RFSH,    0,           30,     2,      INVALID_IMAGE )\

//                                                Enum ID,                Service,         SubService,  Pos X,  Pos Y,  Size X,  Size Y,  Minimum image,    Maximum image     Cursor Image,   Cursor radius,  Start Angle,  End Angle,  Range,  Option,                                       Text PosX,  Text PosY,  Text Size X,  Text Size Y,  Text Color,  Text Alternate Color,  Font ID,             Font Alternate ID,   Text Option,              Text Label,
#define METER_DEF(X_METER)       X_METER(         METER_TEST,             SERV_ID_NONE,    2,           322,    76,     115,     115,     INVALID_IMAGE,    INVALID_IMAGE,    INVALID_IMAGE,  57,             0,            360,        100,    OPTION_CURSOR_PRIORITY,                       15,         44,         75,           28,           0x00FFFFFF,  0x0000FF00,            SYS_FT_16,  SYS_FT_16,  _X_CENTER_Y_CENTER,  INVALID_LABEL        )\

//                                                Enum ID,                Service,         SubService,  Pos X,  Pos Y,  Size X,  Size Y,  Released panel,  Pressed panel   Text PosX,  Text PosY,  Text SizeX,  Text Size Y,  Text Color,  Text Color Pressed,  Font ID,             Font Alternate ID,    Text Option,             Text Label,    Filter
#define PANEL_DEF(X_PANEL)       X_PANEL(         PANEL_TEST,             SERV_ID_NONE,    0,           38,     41,     125,     193,     INVALID_IMAGE,   INVALID_IMAGE,  10,         5,          105,         20,           0x00FFFFFF,  0x000000FF,          SYS_FT_16,      SYS_FT_16,       _X_CENTER_Y_CENTER, INVALID_LABEL,  SERVICE_FILTER_NORMAL    )\

//                                                Enum ID,                Service,         SubService,  Size X, Size Y, Image 1
#define SPRITE_DEF(X_SPRITE)      X_SPRITE(       SPRITE_TEST,            SERV_ID_RFSH,    0,           32,     32,     INVALID_IMAGE  )\


//                                                Enum ID,                Service,         SubService     Pos X,  Pos Y,  Size X,  Size Y
#define VIRTUAL_WINDOW_DEF(X_WINDOW) X_WINDOW(    VIRTUAL_WINDOW_1,       SERV_ID_NONE,    0,             10,     56,     36,      160   )\

//           Enum ID,            Service,      Sub, Px,   Py,   Sx,   Sy,   ResX  ResY  Bar Spacing   Bar Image      Option
#define SPECTRUM_DEF(X_SPECTRUM) \
 X_SPECTRUM( SPECTRUM,           SERV_ID_SPEK, 0,   12,   10,   168,  72,   16,   12,   3,            SPECTRUM_BAR,  GRAFX_OPTION_NONE)\


#endif
//-------------------------------------------------------------------------------------------------










