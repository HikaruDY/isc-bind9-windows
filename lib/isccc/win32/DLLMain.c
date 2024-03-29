/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

#include <signal.h>
#include <windows.h>

/*
 * Called when we enter the DLL
 */
__declspec(dllexport) BOOL WINAPI
	DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch (fdwReason) {
	/*
	 * The DLL is loading due to process
	 * initialization or a call to LoadLibrary.
	 */
	case DLL_PROCESS_ATTACH:
		break;

	/* The attached process creates a new thread.  */
	case DLL_THREAD_ATTACH:
		break;

	/* The thread of the attached process terminates. */
	case DLL_THREAD_DETACH:
		break;

	/*
	 * The DLL is unloading from a process due to
	 * process termination or a call to FreeLibrary.
	 */
	case DLL_PROCESS_DETACH:
		break;

	default:
		break;
	}
	return (TRUE);
}
