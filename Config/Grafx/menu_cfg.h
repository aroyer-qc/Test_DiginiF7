//-------------------------------------------------------------------------------------------------
//
//  File :  Menu_cfg.h
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

//-------------------------------------------------------------------------------------------------
//  Global Variable(s)
//-------------------------------------------------------------------------------------------------

#ifdef GFX_GLOBAL

const PageWidget_t PageLoading          [] =  { {   BACK_LOADING,            INVALID_LINK        },
                                                {   LABEL_SKIN_LOADING,      LINK_MAIN_HUB       },
                                                {   PROGRESS_LOADING,        INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainHub          [] =  { {   VIRTUAL_MAIN_HUB,        INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageJogHub           [] =  {// {   VIRTUAL_JOG_HUB,         INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXY    [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_3,                 LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_3,                 LINK_AXIS_Y         },      //   " Y
                                                {   BOX_3_3,                 LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXZ    [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_3,                 LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_3,                 LINK_AXIS_Z         },      //   " Z
                                                {   BOX_3_3,                 LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXYZ   [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_4,                 LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_4,                 LINK_AXIS_Y         },      //   " Y
                                                {   BOX_3_4,                 LINK_AXIS_Z         },      //   " Z
                                                {   BOX_4_4,                 LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXYT   [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_3T,                LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_3T,                LINK_AXIS_Y         },      //   " Y
                                                {   BOX_3_3T,                LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   BOX_T,                   INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXZT   [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_3T,                LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_3T,                LINK_AXIS_Z         },      //   " Z
                                                {   BOX_3_3T,                LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   BOX_T,                   LINK_PAGE_TERMINAL  },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMainDisplayXYZT  [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_1_4T,                LINK_AXIS_X         },      // Yellow box around axis X information
                                                {   BOX_2_4T,                LINK_AXIS_Y         },      //   " Y
                                                {   BOX_3_4T,                LINK_AXIS_Z         },      //   " Z
                                                {   BOX_4_4T,                LINK_SPINDLE        },      //   " Spindle
                                                {   BTN_SETTING,             LINK_MAIN_MENU      },      // Button to go to setting menu
                                                {   BOX_T,                   LINK_PAGE_TERMINAL  },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageTerminal         [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },      // Button to go to setting menu
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageAxisX            [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
// need backlash adjustment button and label
// need Machine range setting
                                                {   BOX_AXIS,                INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageAxisY            [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
// need backlash adjustment button and label
// need Machine range setting
                                                {   BOX_AXIS,                INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageAxisZ            [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
// need backlash adjustment button and label
// need Machine range setting
                                                {   BOX_AXIS,                INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageSpindle          [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
                                                {   BOX_AXIS,                INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMenu             [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   LABEL_PAGE_MAIN_MENU,    INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_HUB       },
                                                {   BTN_DIAG,                LINK_DIAGNOSTICS    },
                                                {   BTN_INFO,                LINK_PAGE_INFO      },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageMachineSelect    [] =  { {   BACK_DIAMOND,            INVALID_LINK        },      // Background
// Should I add here mm or Inch?
// Should I add here terminal windows or not?
                                                {   BTN_RETURN_DOWN,         PREVIOUS_LINK       },
                                                {   RECT_BLANK_MACHINE,      INVALID_LINK        },     // Erase the display section of the graphic representatio
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t InputTestMenu        [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   BTN_RETURN,              LINK_MAIN_MENU      },
                                                {   INVALID_WIDGET,          INVALID_LINK        }

          };

const PageWidget_t InputData            [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   LABEL_INPT_TITLE,        INVALID_LINK        },
                                                {   BOX_EDIT,                INVALID_LINK        },
                                                {   LABEL_PRINT_NUMBER,      INVALID_LINK        },
                                                {   BTN_1,                   INVALID_LINK        },
                                                {   BTN_2,                   INVALID_LINK        },
                                                {   BTN_3,                   INVALID_LINK        },
                                                {   BTN_4,                   INVALID_LINK        },
                                                {   BTN_5,                   INVALID_LINK        },
                                                {   BTN_6,                   INVALID_LINK        },
                                                {   BTN_7,                   INVALID_LINK        },
                                                {   BTN_8,                   INVALID_LINK        },
                                                {   BTN_9,                   INVALID_LINK        },
                                                {   BTN_0,                   INVALID_LINK        },
                                                {   BTN_DOT,                 INVALID_LINK        },
                                                {   BTN_TOGGLE_SIGN,         INVALID_LINK        },
                                                {   BTN_DEL,                 INVALID_LINK        },
                                                {   BTN_OK,                  PREVIOUS_LINK       },
                                                {   BTN_CANCEL,              PREVIOUS_LINK       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t InputDataHexa        [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   LABEL_INPT_TITLE,        INVALID_LINK        },
                                                {   LABEL_PRINT_NUMBER,      INVALID_LINK        },
                                                {   BOX_EDIT,                INVALID_LINK        },
                                                {   BTN_1,                   INVALID_LINK        },
                                                {   BTN_2,                   INVALID_LINK        },
                                                {   BTN_3,                   INVALID_LINK        },
                                                {   BTN_4,                   INVALID_LINK        },
                                                {   BTN_5,                   INVALID_LINK        },
                                                {   BTN_6,                   INVALID_LINK        },
                                                {   BTN_7,                   INVALID_LINK        },
                                                {   BTN_8,                   INVALID_LINK        },
                                                {   BTN_9,                   INVALID_LINK        },
                                                {   BTN_0,                   INVALID_LINK        },
                                                {   BTN_A,                   INVALID_LINK        },
                                                {   BTN_B,                   INVALID_LINK        },
                                                {   BTN_C,                   INVALID_LINK        },
                                                {   BTN_D,                   INVALID_LINK        },
                                                {   BTN_E,                   INVALID_LINK        },
                                                {   BTN_F,                   INVALID_LINK        },
                                                {   BTN_DEL,                 INVALID_LINK        },
                                                {   BTN_OK,                  PREVIOUS_LINK       },
                                                {   BTN_CANCEL,              PREVIOUS_LINK       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageDiagnostic       [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   BTN_RETURN_DOWN,         PREVIOUS_LINK       },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

const PageWidget_t PageInfo             [] =  { {   BACK_DIAMOND,            INVALID_LINK        },
                                                {   BTN_RETURN_DOWN,         PREVIOUS_LINK       },
                                                {   LABEL_INFO,              INVALID_LINK        },
                                                {   LABEL_FW_NAME_INFO,      INVALID_LINK        },
                                                {   LABEL_FW_VERSION_INFO,   INVALID_LINK        },
                                                {   LABEL_GUI_NAME_INFO,     INVALID_LINK        },
                                                {   LABEL_GUI_VERSION_INFO,  INVALID_LINK        },
                                                {   LABEL_HARDWARE_INFO,     INVALID_LINK        },
                                                {   LABEL_SERIAL_INFO,       INVALID_LINK        },
                                                {   LABEL_COMPILE_DATE_INFO, INVALID_LINK        },
                                                {   LABEL_INFO_FIRMWARE,     INVALID_LINK        },
                                                {   LABEL_INFO_VERSION,      INVALID_LINK        },
                                                {   LABEL_INFO_GUI_FIRMWARE, INVALID_LINK        },
                                                {   LABEL_INFO_GUI_VERSION,  INVALID_LINK        },
                                                {   LABEL_INFO_HARDWARE,     INVALID_LINK        },
                                                {   LABEL_INFO_SERIAL,       INVALID_LINK        },
                                                {   LABEL_INFO_DATE,         INVALID_LINK        },
                                                {   INVALID_WIDGET,          INVALID_LINK        }
                                              };

#endif  // GFX_GLOBAL

//-------------------------------------------------------------------------------------------------

//                                                 {   BTN_DIAL_TEST,           LINK_PAGE_DIAL      },




