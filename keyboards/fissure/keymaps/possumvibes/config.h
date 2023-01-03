#pragma once

#undef DEBOUNCE
#define DEBOUNCE 7

// SPACE SAVERS WHEN NOT DEBUGGING
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
