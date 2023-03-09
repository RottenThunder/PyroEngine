#pragma once
#include <unordered_map>
#include "Base.h"
#include "KeyCodes.h"
#include "MouseButtonCodes.h"
#include <GLFW/glfw3.h>

namespace PyroEngine
{
	static std::unordered_map<uint32_t, int> s_PyroToOpenGLKeyCodes =
	{
		//Number Keys
		{ PYRO_KEY_0				, GLFW_KEY_0             },
		{ PYRO_KEY_1				, GLFW_KEY_1             },
		{ PYRO_KEY_2				, GLFW_KEY_2             },
		{ PYRO_KEY_3				, GLFW_KEY_3             },
		{ PYRO_KEY_4				, GLFW_KEY_4             },
		{ PYRO_KEY_5				, GLFW_KEY_5             },
		{ PYRO_KEY_6				, GLFW_KEY_6             },
		{ PYRO_KEY_7				, GLFW_KEY_7             },
		{ PYRO_KEY_8				, GLFW_KEY_8             },
		{ PYRO_KEY_9				, GLFW_KEY_9             },

		//Letter Keys
		{ PYRO_KEY_A				, GLFW_KEY_A             },
		{ PYRO_KEY_B				, GLFW_KEY_B             },
		{ PYRO_KEY_C				, GLFW_KEY_C             },
		{ PYRO_KEY_D				, GLFW_KEY_D             },
		{ PYRO_KEY_E				, GLFW_KEY_E             },
		{ PYRO_KEY_F				, GLFW_KEY_F             },
		{ PYRO_KEY_G				, GLFW_KEY_G             },
		{ PYRO_KEY_H				, GLFW_KEY_H             },
		{ PYRO_KEY_I				, GLFW_KEY_I             },
		{ PYRO_KEY_J				, GLFW_KEY_J             },
		{ PYRO_KEY_K				, GLFW_KEY_K             },
		{ PYRO_KEY_L				, GLFW_KEY_L             },
		{ PYRO_KEY_M				, GLFW_KEY_M             },
		{ PYRO_KEY_N				, GLFW_KEY_N             },
		{ PYRO_KEY_O				, GLFW_KEY_O             },
		{ PYRO_KEY_P				, GLFW_KEY_P             },
		{ PYRO_KEY_Q				, GLFW_KEY_Q             },
		{ PYRO_KEY_R				, GLFW_KEY_R             },
		{ PYRO_KEY_S				, GLFW_KEY_S             },
		{ PYRO_KEY_T				, GLFW_KEY_T             },
		{ PYRO_KEY_U				, GLFW_KEY_U             },
		{ PYRO_KEY_V				, GLFW_KEY_V             },
		{ PYRO_KEY_W				, GLFW_KEY_W             },
		{ PYRO_KEY_X				, GLFW_KEY_X             },
		{ PYRO_KEY_Y				, GLFW_KEY_Y             },
		{ PYRO_KEY_Z				, GLFW_KEY_Z             },

		//Function Keys
		{ PYRO_KEY_F1				, GLFW_KEY_F1            },
		{ PYRO_KEY_F2				, GLFW_KEY_F2            },
		{ PYRO_KEY_F3				, GLFW_KEY_F3            },
		{ PYRO_KEY_F4				, GLFW_KEY_F4            },
		{ PYRO_KEY_F5				, GLFW_KEY_F5            },
		{ PYRO_KEY_F6				, GLFW_KEY_F6            },
		{ PYRO_KEY_F7				, GLFW_KEY_F7            },
		{ PYRO_KEY_F8				, GLFW_KEY_F8            },
		{ PYRO_KEY_F9				, GLFW_KEY_F9            },
		{ PYRO_KEY_F10				, GLFW_KEY_F10           },
		{ PYRO_KEY_F11				, GLFW_KEY_F11           },
		{ PYRO_KEY_F12				, GLFW_KEY_F12           },
		{ PYRO_KEY_F13				, GLFW_KEY_F13           },
		{ PYRO_KEY_F14				, GLFW_KEY_F14           },
		{ PYRO_KEY_F15				, GLFW_KEY_F15           },
		{ PYRO_KEY_F16				, GLFW_KEY_F16           },
		{ PYRO_KEY_F17				, GLFW_KEY_F17           },
		{ PYRO_KEY_F18				, GLFW_KEY_F18           },
		{ PYRO_KEY_F19				, GLFW_KEY_F19           },
		{ PYRO_KEY_F20				, GLFW_KEY_F20           },
		{ PYRO_KEY_F21				, GLFW_KEY_F21           },
		{ PYRO_KEY_F22				, GLFW_KEY_F22           },
		{ PYRO_KEY_F23				, GLFW_KEY_F23           },
		{ PYRO_KEY_F24				, GLFW_KEY_F24           },
		{ PYRO_KEY_F25				, GLFW_KEY_F25           },

		//Keypad
		{ PYRO_KEY_KEYPAD_0			, GLFW_KEY_KP_0          },
		{ PYRO_KEY_KEYPAD_1			, GLFW_KEY_KP_1          },
		{ PYRO_KEY_KEYPAD_2			, GLFW_KEY_KP_2          },
		{ PYRO_KEY_KEYPAD_3			, GLFW_KEY_KP_3          },
		{ PYRO_KEY_KEYPAD_4			, GLFW_KEY_KP_4          },
		{ PYRO_KEY_KEYPAD_5			, GLFW_KEY_KP_5          },
		{ PYRO_KEY_KEYPAD_6			, GLFW_KEY_KP_6          },
		{ PYRO_KEY_KEYPAD_7			, GLFW_KEY_KP_7          },
		{ PYRO_KEY_KEYPAD_8			, GLFW_KEY_KP_8          },
		{ PYRO_KEY_KEYPAD_9			, GLFW_KEY_KP_9          },
		{ PYRO_KEY_KEYPAD_ADD		, GLFW_KEY_KP_ADD        },
		{ PYRO_KEY_KEYPAD_SUBTRACT	, GLFW_KEY_KP_SUBTRACT   },
		{ PYRO_KEY_KEYPAD_MULTIPLY	, GLFW_KEY_KP_MULTIPLY   },
		{ PYRO_KEY_KEYPAD_DIVIDE	, GLFW_KEY_KP_DIVIDE     },
		{ PYRO_KEY_KEYPAD_EQUAL		, GLFW_KEY_KP_EQUAL      },
		{ PYRO_KEY_KEYPAD_DECIMAL	, GLFW_KEY_KP_DECIMAL    },
		{ PYRO_KEY_KEYPAD_ENTER		, GLFW_KEY_KP_ENTER      },

		//Arrow Keys
		{ PYRO_KEY_ARROW_RIGHT		, GLFW_KEY_RIGHT         },
		{ PYRO_KEY_ARROW_LEFT	    , GLFW_KEY_LEFT          },
		{ PYRO_KEY_ARROW_DOWN		, GLFW_KEY_DOWN          },
		{ PYRO_KEY_ARROW_UP			, GLFW_KEY_UP            },

		//Misc Keys
		{ PYRO_KEY_MINUS			, GLFW_KEY_MINUS         },
		{ PYRO_KEY_EQUALS			, GLFW_KEY_EQUAL         },
		{ PYRO_KEY_LEFT_BRACKET		, GLFW_KEY_LEFT_BRACKET  },
		{ PYRO_KEY_RIGHT_BRACKET	, GLFW_KEY_RIGHT_BRACKET },
		{ PYRO_KEY_SEMICOLON		, GLFW_KEY_SEMICOLON     },
		{ PYRO_KEY_APOSTROPHE		, GLFW_KEY_APOSTROPHE    },
		{ PYRO_KEY_COMMA			, GLFW_KEY_COMMA         },
		{ PYRO_KEY_FULL_STOP		, GLFW_KEY_PERIOD        },
		{ PYRO_KEY_SLASH			, GLFW_KEY_SLASH         },
		{ PYRO_KEY_BACKSLASH		, GLFW_KEY_BACKSLASH     },
		{ PYRO_KEY_SPACE            , GLFW_KEY_SPACE         },
		{ PYRO_KEY_GRAVE_ACCENT		, GLFW_KEY_GRAVE_ACCENT  },
		{ PYRO_KEY_ENTER			, GLFW_KEY_ENTER         },
		{ PYRO_KEY_TAB				, GLFW_KEY_TAB           },
		{ PYRO_KEY_BACKSPACE		, GLFW_KEY_BACKSPACE     },
		{ PYRO_KEY_INSERT			, GLFW_KEY_INSERT        },
		{ PYRO_KEY_DELETE			, GLFW_KEY_DELETE        },
		{ PYRO_KEY_PAGE_UP			, GLFW_KEY_PAGE_UP       },
		{ PYRO_KEY_PAGE_DOWN		, GLFW_KEY_PAGE_DOWN     },
		{ PYRO_KEY_HOME				, GLFW_KEY_HOME          },
		{ PYRO_KEY_END				, GLFW_KEY_END           },
		{ PYRO_KEY_CAPS_LOCK		, GLFW_KEY_CAPS_LOCK     },
		{ PYRO_KEY_SCROLL_LOCK		, GLFW_KEY_SCROLL_LOCK   },
		{ PYRO_KEY_NUM_LOCK			, GLFW_KEY_NUM_LOCK      },
		{ PYRO_KEY_PRINT_SCREEN		, GLFW_KEY_PRINT_SCREEN  },
		{ PYRO_KEY_PAUSE			, GLFW_KEY_PAUSE         },
		{ PYRO_KEY_LEFT_SHIFT		, GLFW_KEY_LEFT_SHIFT    },
		{ PYRO_KEY_LEFT_CONTROL		, GLFW_KEY_LEFT_CONTROL  },
		{ PYRO_KEY_LEFT_ALT			, GLFW_KEY_LEFT_ALT      },
		{ PYRO_KEY_LEFT_SUPER		, GLFW_KEY_LEFT_SUPER    },
		{ PYRO_KEY_RIGHT_SHIFT		, GLFW_KEY_RIGHT_SHIFT   },
		{ PYRO_KEY_RIGHT_CONTROL	, GLFW_KEY_RIGHT_CONTROL },
		{ PYRO_KEY_RIGHT_ALT		, GLFW_KEY_RIGHT_ALT     },
		{ PYRO_KEY_RIGHT_SUPER		, GLFW_KEY_RIGHT_SUPER   },
		{ PYRO_KEY_MENU				, GLFW_KEY_MENU          },
		{ PYRO_KEY_WORLD_1			, GLFW_KEY_WORLD_1       },
		{ PYRO_KEY_WORLD_2			, GLFW_KEY_WORLD_2       },
		{ PYRO_KEY_ESCAPE           , GLFW_KEY_ESCAPE        }
	};

	static std::unordered_map<int, uint32_t> s_OpenGLToPyroKeyCodes =
	{
		//Number Keys
		{ GLFW_KEY_0				, PYRO_KEY_0             },
		{ GLFW_KEY_1				, PYRO_KEY_1             },
		{ GLFW_KEY_2				, PYRO_KEY_2             },
		{ GLFW_KEY_3				, PYRO_KEY_3             },
		{ GLFW_KEY_4				, PYRO_KEY_4             },
		{ GLFW_KEY_5				, PYRO_KEY_5             },
		{ GLFW_KEY_6				, PYRO_KEY_6             },
		{ GLFW_KEY_7				, PYRO_KEY_7             },
		{ GLFW_KEY_8				, PYRO_KEY_8             },
		{ GLFW_KEY_9				, PYRO_KEY_9             },

		//Letter Keys
		{ GLFW_KEY_A				, PYRO_KEY_A             },
		{ GLFW_KEY_B				, PYRO_KEY_B             },
		{ GLFW_KEY_C				, PYRO_KEY_C             },
		{ GLFW_KEY_D				, PYRO_KEY_D             },
		{ GLFW_KEY_E				, PYRO_KEY_E             },
		{ GLFW_KEY_F				, PYRO_KEY_F             },
		{ GLFW_KEY_G				, PYRO_KEY_G             },
		{ GLFW_KEY_H				, PYRO_KEY_H             },
		{ GLFW_KEY_I				, PYRO_KEY_I             },
		{ GLFW_KEY_J				, PYRO_KEY_J             },
		{ GLFW_KEY_K				, PYRO_KEY_K             },
		{ GLFW_KEY_L				, PYRO_KEY_L             },
		{ GLFW_KEY_M				, PYRO_KEY_M             },
		{ GLFW_KEY_N				, PYRO_KEY_N             },
		{ GLFW_KEY_O				, PYRO_KEY_O             },
		{ GLFW_KEY_P				, PYRO_KEY_P             },
		{ GLFW_KEY_Q				, PYRO_KEY_Q             },
		{ GLFW_KEY_R				, PYRO_KEY_R             },
		{ GLFW_KEY_S				, PYRO_KEY_S             },
		{ GLFW_KEY_T				, PYRO_KEY_T             },
		{ GLFW_KEY_U				, PYRO_KEY_U             },
		{ GLFW_KEY_V				, PYRO_KEY_V             },
		{ GLFW_KEY_W				, PYRO_KEY_W             },
		{ GLFW_KEY_X				, PYRO_KEY_X             },
		{ GLFW_KEY_Y				, PYRO_KEY_Y             },
		{ GLFW_KEY_Z				, PYRO_KEY_Z             },

		//Function Keys
		{ GLFW_KEY_F1				, PYRO_KEY_F1            },
		{ GLFW_KEY_F2				, PYRO_KEY_F2            },
		{ GLFW_KEY_F3				, PYRO_KEY_F3            },
		{ GLFW_KEY_F4				, PYRO_KEY_F4            },
		{ GLFW_KEY_F5				, PYRO_KEY_F5            },
		{ GLFW_KEY_F6				, PYRO_KEY_F6            },
		{ GLFW_KEY_F7				, PYRO_KEY_F7            },
		{ GLFW_KEY_F8				, PYRO_KEY_F8            },
		{ GLFW_KEY_F9				, PYRO_KEY_F9            },
		{ GLFW_KEY_F10				, PYRO_KEY_F10           },
		{ GLFW_KEY_F11				, PYRO_KEY_F11           },
		{ GLFW_KEY_F12				, PYRO_KEY_F12           },
		{ GLFW_KEY_F13				, PYRO_KEY_F13           },
		{ GLFW_KEY_F14				, PYRO_KEY_F14           },
		{ GLFW_KEY_F15				, PYRO_KEY_F15           },
		{ GLFW_KEY_F16				, PYRO_KEY_F16           },
		{ GLFW_KEY_F17				, PYRO_KEY_F17           },
		{ GLFW_KEY_F18				, PYRO_KEY_F18           },
		{ GLFW_KEY_F19				, PYRO_KEY_F19           },
		{ GLFW_KEY_F20				, PYRO_KEY_F20           },
		{ GLFW_KEY_F21				, PYRO_KEY_F21           },
		{ GLFW_KEY_F22				, PYRO_KEY_F22           },
		{ GLFW_KEY_F23				, PYRO_KEY_F23           },
		{ GLFW_KEY_F24				, PYRO_KEY_F24           },
		{ GLFW_KEY_F25				, PYRO_KEY_F25           },

		//Keypad
		{ GLFW_KEY_KP_0			, PYRO_KEY_KEYPAD_0          },
		{ GLFW_KEY_KP_1			, PYRO_KEY_KEYPAD_1          },
		{ GLFW_KEY_KP_2			, PYRO_KEY_KEYPAD_2          },
		{ GLFW_KEY_KP_3			, PYRO_KEY_KEYPAD_3          },
		{ GLFW_KEY_KP_4			, PYRO_KEY_KEYPAD_4          },
		{ GLFW_KEY_KP_5			, PYRO_KEY_KEYPAD_5          },
		{ GLFW_KEY_KP_6			, PYRO_KEY_KEYPAD_6          },
		{ GLFW_KEY_KP_7			, PYRO_KEY_KEYPAD_7          },
		{ GLFW_KEY_KP_8			, PYRO_KEY_KEYPAD_8          },
		{ GLFW_KEY_KP_9			, PYRO_KEY_KEYPAD_9          },
		{ GLFW_KEY_KP_ADD		, PYRO_KEY_KEYPAD_ADD        },
		{ GLFW_KEY_KP_SUBTRACT	, PYRO_KEY_KEYPAD_SUBTRACT   },
		{ GLFW_KEY_KP_MULTIPLY	, PYRO_KEY_KEYPAD_MULTIPLY   },
		{ GLFW_KEY_KP_DIVIDE	, PYRO_KEY_KEYPAD_DIVIDE     },
		{ GLFW_KEY_KP_EQUAL		, PYRO_KEY_KEYPAD_EQUAL      },
		{ GLFW_KEY_KP_DECIMAL	, PYRO_KEY_KEYPAD_DECIMAL    },
		{ GLFW_KEY_KP_ENTER		, PYRO_KEY_KEYPAD_ENTER      },

		//Arrow Keys
		{ GLFW_KEY_RIGHT		, PYRO_KEY_ARROW_RIGHT       },
		{ GLFW_KEY_LEFT	        , PYRO_KEY_ARROW_LEFT        },
		{ GLFW_KEY_DOWN		    , PYRO_KEY_ARROW_DOWN        },
		{ GLFW_KEY_UP			, PYRO_KEY_ARROW_UP          },

		//Misc Keys
		{ GLFW_KEY_MINUS			, PYRO_KEY_MINUS         },
		{ GLFW_KEY_EQUAL			, PYRO_KEY_EQUALS        },
		{ GLFW_KEY_LEFT_BRACKET		, PYRO_KEY_LEFT_BRACKET  },
		{ GLFW_KEY_RIGHT_BRACKET	, PYRO_KEY_RIGHT_BRACKET },
		{ GLFW_KEY_SEMICOLON		, PYRO_KEY_SEMICOLON     },
		{ GLFW_KEY_APOSTROPHE		, PYRO_KEY_APOSTROPHE    },
		{ GLFW_KEY_COMMA			, PYRO_KEY_COMMA         },
		{ GLFW_KEY_PERIOD		    , PYRO_KEY_FULL_STOP     },
		{ GLFW_KEY_SLASH			, PYRO_KEY_SLASH         },
		{ GLFW_KEY_BACKSLASH		, PYRO_KEY_BACKSLASH     },
		{ GLFW_KEY_SPACE            , PYRO_KEY_SPACE         },
		{ GLFW_KEY_GRAVE_ACCENT		, PYRO_KEY_GRAVE_ACCENT  },
		{ GLFW_KEY_ENTER			, PYRO_KEY_ENTER         },
		{ GLFW_KEY_TAB				, PYRO_KEY_TAB           },
		{ GLFW_KEY_BACKSPACE		, PYRO_KEY_BACKSPACE     },
		{ GLFW_KEY_INSERT			, PYRO_KEY_INSERT        },
		{ GLFW_KEY_DELETE			, PYRO_KEY_DELETE        },
		{ GLFW_KEY_PAGE_UP			, PYRO_KEY_PAGE_UP       },
		{ GLFW_KEY_PAGE_DOWN		, PYRO_KEY_PAGE_DOWN     },
		{ GLFW_KEY_HOME				, PYRO_KEY_HOME          },
		{ GLFW_KEY_END				, PYRO_KEY_END           },
		{ GLFW_KEY_CAPS_LOCK		, PYRO_KEY_CAPS_LOCK     },
		{ GLFW_KEY_SCROLL_LOCK		, PYRO_KEY_SCROLL_LOCK   },
		{ GLFW_KEY_NUM_LOCK			, PYRO_KEY_NUM_LOCK      },
		{ GLFW_KEY_PRINT_SCREEN		, PYRO_KEY_PRINT_SCREEN  },
		{ GLFW_KEY_PAUSE			, PYRO_KEY_PAUSE         },
		{ GLFW_KEY_LEFT_SHIFT		, PYRO_KEY_LEFT_SHIFT    },
		{ GLFW_KEY_LEFT_CONTROL		, PYRO_KEY_LEFT_CONTROL  },
		{ GLFW_KEY_LEFT_ALT			, PYRO_KEY_LEFT_ALT      },
		{ GLFW_KEY_LEFT_SUPER		, PYRO_KEY_LEFT_SUPER    },
		{ GLFW_KEY_RIGHT_SHIFT		, PYRO_KEY_RIGHT_SHIFT   },
		{ GLFW_KEY_RIGHT_CONTROL	, PYRO_KEY_RIGHT_CONTROL },
		{ GLFW_KEY_RIGHT_ALT		, PYRO_KEY_RIGHT_ALT     },
		{ GLFW_KEY_RIGHT_SUPER		, PYRO_KEY_RIGHT_SUPER   },
		{ GLFW_KEY_MENU				, PYRO_KEY_MENU          },
		{ GLFW_KEY_WORLD_1			, PYRO_KEY_WORLD_1       },
		{ GLFW_KEY_WORLD_2			, PYRO_KEY_WORLD_2       },
		{ GLFW_KEY_ESCAPE           , PYRO_KEY_ESCAPE        }
	};

	static std::unordered_map<uint32_t, int> s_PyroToOpenGLMouseButtonCodes =
	{
		{ PYRO_MOUSE_BUTTON_1      , GLFW_MOUSE_BUTTON_1      },
		{ PYRO_MOUSE_BUTTON_2      , GLFW_MOUSE_BUTTON_2      },
		{ PYRO_MOUSE_BUTTON_3      , GLFW_MOUSE_BUTTON_3      },
		{ PYRO_MOUSE_BUTTON_4      , GLFW_MOUSE_BUTTON_4      },
		{ PYRO_MOUSE_BUTTON_5      , GLFW_MOUSE_BUTTON_5      },
		{ PYRO_MOUSE_BUTTON_6      , GLFW_MOUSE_BUTTON_6      },
		{ PYRO_MOUSE_BUTTON_7      , GLFW_MOUSE_BUTTON_7      },
		{ PYRO_MOUSE_BUTTON_8      , GLFW_MOUSE_BUTTON_8      },
		{ PYRO_MOUSE_BUTTON_LEFT   , GLFW_MOUSE_BUTTON_LEFT   },
		{ PYRO_MOUSE_BUTTON_RIGHT  , GLFW_MOUSE_BUTTON_RIGHT  },
		{ PYRO_MOUSE_BUTTON_MIDDLE , GLFW_MOUSE_BUTTON_MIDDLE }
	};

	static std::unordered_map<int, uint32_t> s_OpenGLToPyroMouseButtonCodes =
	{
		{ GLFW_MOUSE_BUTTON_1      , PYRO_MOUSE_BUTTON_1      },
		{ GLFW_MOUSE_BUTTON_2      , PYRO_MOUSE_BUTTON_2      },
		{ GLFW_MOUSE_BUTTON_3      , PYRO_MOUSE_BUTTON_3      },
		{ GLFW_MOUSE_BUTTON_4      , PYRO_MOUSE_BUTTON_4      },
		{ GLFW_MOUSE_BUTTON_5      , PYRO_MOUSE_BUTTON_5      },
		{ GLFW_MOUSE_BUTTON_6      , PYRO_MOUSE_BUTTON_6      },
		{ GLFW_MOUSE_BUTTON_7      , PYRO_MOUSE_BUTTON_7      },
		{ GLFW_MOUSE_BUTTON_8      , PYRO_MOUSE_BUTTON_8      },
		{ GLFW_MOUSE_BUTTON_LEFT   , PYRO_MOUSE_BUTTON_LEFT   },
		{ GLFW_MOUSE_BUTTON_RIGHT  , PYRO_MOUSE_BUTTON_RIGHT  },
		{ GLFW_MOUSE_BUTTON_MIDDLE , PYRO_MOUSE_BUTTON_MIDDLE }
	};

	class Input
	{
	private:
		static Input* s_Instance;
	protected:
		virtual bool IsKeyPressedImpl(uint32_t keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(uint32_t mouseButton) = 0;
		//TODO: Need to add a function to get the Mouse Position as a Vector2
		virtual double GetMouseXImpl() = 0;
		virtual double GetMouseYImpl() = 0;
	public:
		inline static bool IsKeyPressed(uint32_t keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(uint32_t mouseButton) { return s_Instance->IsMouseButtonPressedImpl(mouseButton); }
		inline static double GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static double GetMouseY() { return s_Instance->GetMouseYImpl(); }
	};
}