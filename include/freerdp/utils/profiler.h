/*
   FreeRDP: A Remote Desktop Protocol client.
   Profiler Utils

   Copyright 2011 Stephen Erisman

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __UTILS_PROFILER_H
#define __UTILS_PROFILER_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

#include <freerdp/utils/memory.h>
#include <freerdp/utils/stopwatch.h>

struct _PROFILER
{
	char *name;	
	STOPWATCH *stopwatch;
};
typedef struct _PROFILER PROFILER;

PROFILER * profiler_create(char * name);
void profiler_free(PROFILER * profiler);

void profiler_enter(PROFILER * profiler);
void profiler_exit(PROFILER * profiler);

void profiler_print_header();
void profiler_print(PROFILER * profiler);
void profiler_print_footer();

#ifdef WITH_PROFILER
#define IF_PROFILER(then)			then
#define PROFILER_DEFINE(prof)		PROFILER * prof
#define PROFILER_CREATE(prof,name)	prof = profiler_create(name)
#define PROFILER_FREE(prof)			profiler_free(prof)
#define PROFILER_ENTER(prof)		profiler_enter(prof)
#define PROFILER_EXIT(prof)			profiler_exit(prof)
#define PROFILER_PRINT_HEADER		profiler_print_header()
#define PROFILER_PRINT(prof)		profiler_print(prof)
#define PROFILER_PRINT_FOOTER		profiler_print_footer()
#else
#define IF_PROFILER(then)			;
#define PROFILER_DEFINE(prof)		;
#define PROFILER_CREATE(prof,name)	;
#define PROFILER_FREE(prof)			;
#define PROFILER_ENTER(prof)		;
#define PROFILER_EXIT(prof)			;
#define PROFILER_PRINT_HEADER		;
#define PROFILER_PRINT(prof)		;
#define PROFILER_PRINT_FOOTER		;
#endif

#endif /* __UTILS_PROFILER_H */