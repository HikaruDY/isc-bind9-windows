/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

/*
 * win32 configuration file
 * All definitions, declarations, macros and includes are
 * specific to the requirements of the Windows NT and Windows 2000
 * platforms
 */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define as __inline if that's what the C compiler calls it.  */
#define inline __inline

/* Define to `unsigned int/__int64' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/*
 * ANSI C compliance enabled
 */
#define __STDC__ 1

/*
 * Silence compiler warnings about using strcpy and friends.
 */
#define _CRT_SECURE_NO_DEPRECATE 1

/*
 * Use 32 bit time.
 */
#ifndef _WIN64
#define _USE_32BIT_TIME_T 1
#endif

/*
 * Minimum version is Windows 8 and Windows Server 2012
 */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0602
#endif
#if _WIN32_WINNT < 0x0602
#error Minimum Target environment is Windows 8 and Windows Server 2012
#endif
#ifndef NTDDI_VERSION
#define NTDDI_VERSION 0x06020000
#endif
#if NTDDI_VERSION < 0x06020000
#error Minimum Target environment is Windows 8 and Windows Server 2012
#endif

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* define on DEC OSF to enable 4.4BSD style sa_len support */
/* #undef _SOCKADDR_LEN */

/* define if your system has sigwait() */
/* #undef HAVE_SIGWAIT */

/* define on Solaris to get sigwait() to work using pthreads semantics */
/* #undef _POSIX_PTHREAD_SEMANTICS */

/* define if you need to #define _XPG4_2 before including sys/socket.h */
/* #undef NEED_XPG4_2_BEFORE_SOCKET_H */

/* define if you need to #define _XOPEN_SOURCE_ENTENDED before including
 * sys/socket.h
 */
/* #undef NEED_XSE_BEFORE_SOCKET_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <sys/sockio.h> header file.  */
#define HAVE_SYS_SOCKIO_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the c_r library (-lc_r).  */
/* #undef HAVE_LIBC_R */

/* Define if you have the nsl library (-lnsl).  */
/* #undef HAVE_LIBNSL */

/* Define if you have the pthread library (-lpthread).  */
/* #undef HAVE_LIBPTHREAD */

/* Define if you have the socket library (-lsocket).  */
/* #undef HAVE_LIBSOCKET */

/* Define if you have h_errno */
#define HAVE_H_ERRNO

/* Define if you have getpassphrase in the C library. */
#define HAVE_GETPASSPHRASE

char *getpassphrase(const char *);

/*
 * Define to 1 if you want to use the DLZ "dlopen" driver
 * (which has the same name on windows even though it uses
 * LoadLibrary() instead of dlopen()).
 */
#define ISC_DLZ_DLOPEN 1

#define S_IFMT   _S_IFMT         /* file type mask */
#define S_IFDIR  _S_IFDIR        /* directory */
#define S_IFCHR  _S_IFCHR        /* character special */
#define S_IFIFO  _S_IFIFO        /* pipe */
#define S_IFREG  _S_IFREG        /* regular */
#define S_IREAD  _S_IREAD        /* read permission, owner */
#define S_IWRITE _S_IWRITE       /* write permission, owner */
#define S_IEXEC  _S_IEXEC        /* execute/search permission, owner */

#define O_RDONLY        _O_RDONLY
#define O_WRONLY        _O_WRONLY
#define O_RDWR          _O_RDWR
#define O_APPEND        _O_APPEND
#define O_CREAT         _O_CREAT
#define O_TRUNC         _O_TRUNC
#define O_EXCL          _O_EXCL

/* open() under unix allows setting of read/write permissions
 * at the owner, group and other levels.  These don't exist in NT
 * We'll just map them all to the NT equivalent
 */

#define S_IRUSR _S_IREAD	/* Owner read permission */
#define S_IWUSR _S_IWRITE	/* Owner write permission */
#define S_IRGRP _S_IREAD	/* Group read permission */
#define S_IWGRP _S_IWRITE	/* Group write permission */
#define S_IROTH _S_IREAD	/* Other read permission */
#define S_IWOTH _S_IWRITE	/* Other write permission */


/*
 * WIN32 specials until some other way of dealing with these is decided.
 */

#if _MSC_VER < 1900
#define snprintf _snprintf
#endif
#if _MSC_VER < 1800
#error Use Visual Studio 2013 or later for %zu support.
#endif
#if _MSC_VER <= 1400
#define vsnprintf _vsnprintf
#endif
#define strcasecmp  _stricmp
#define strncasecmp _strnicmp
#define strdup _strdup
#define sopen _sopen
#define isascii __isascii
#ifndef _WIN64
#define stat _stat
#define fstat _fstat
#else
#define stat _stat64
#define fstat _fstat64
#endif
#define fileno _fileno
#define unlink _unlink
#define chdir _chdir
#define mkdir _mkdir
#define rmdir _rmdir
#define getcwd _getcwd
#define utime _utime
#define utimbuf _utimbuf
#ifndef _WIN64
#define lseek _lseek
#else
#define lseek _lseeki64
#endif

/* #define EAFNOSUPPORT EINVAL */
#define chmod _chmod
#define getpid _getpid
#define getppid _getpid	/* WARNING!!! For now this gets the same pid */
#define random rand	/* Random number generator */
#define srandom srand	/* Random number generator seeding */
/* for the config file */
typedef unsigned int    uid_t;          /* user id */
typedef unsigned int    gid_t;          /* group id */
typedef long pid_t;			/* PID */
#ifndef _WIN64
typedef int ssize_t;
typedef long off_t;
#else
typedef __int64 ssize_t;
#ifndef _AFX
/* BINDInstall defines it with another type but doesn't use it */
typedef __int64 off_t;
#endif
#endif

/*
 * Set up the Version Information
 */
#include <versions.h>

#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

/*
 * Applications may need to get the configuration path
 */
#ifndef _USRDLL
#include <isc/ntpaths.h>
#endif

#define fdopen	_fdopen
#define read	_read
#define open	_open
#define close	_close
#define write	_write
#include <io.h>
#define isatty	_isatty

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */
#endif

/*
 * Make the number of available sockets large
 * The number of sockets needed can get large and memory's cheap
 * This must be defined before winsock2.h gets included as the
 * macro is used there.
 */

#ifndef FD_SETSIZE
#define FD_SETSIZE 16384
#endif
#include <windows.h>

/*
 * main() is hooked
 */
#define ISC_MAIN_HOOK 1

/*
 * Configure sensible arguments
 */
#define CONFIGARGS "''"

/*
 * Define if libxml2 is present
 */
#define HAVE_LIBXML2 1

/* Define to enable "rrset-order fixed" syntax. */
/* #undef DNS_RDATASET_FIXED */

/* Define if OpenSSL includes Ed25519 support */
#define HAVE_OPENSSL_ED25519 1

/* Define if OpenSSL includes Ed448 support */
#define HAVE_OPENSSL_ED448 1

/* Define if your OpenSSL version supports DH functions. */
#define HAVE_DH_GET0_KEY 1

/* Define if your OpenSSL version supports ECDSA functions. */
#define HAVE_ECDSA_SIG_GET0 1

/* Define if your OpenSSL version supports RSA functions. */
#define HAVE_RSA_SET0_KEY 1

/* define if OpenSSL is used for Public-Key Cryptography */
#define USE_OPENSSL 1

/* Define if native PKCS#11 is used as cryptographic library provider */
/* #undef USE_PKCS11 */

/* Define to 1 if you have the `readline' function. */
/* #undef HAVE_READLINE */

/* Build with GeoIP2 support */
/* #undef HAVE_GEOIP2 */

/* define if idnkit support is to be included. */
/* #undef WITH_IDN */

/* Define if zlib was found */
/* #undef HAVE_ZLIB */

/* From enable developer */
/* #undef ISC_LIST_CHECKINIT */

/* Large system tuning */
#define TUNE_LARGE 1

/* define if we can use backtrace */
#define USE_BACKTRACE 1

/* the default value of dnssec-validation option */
#define VALIDATION_DEFAULT "auto"

/* Verbose query trace logging */
/* #undef WANT_QUERYTRACE */

/* Define to 1 if you have the `CRYPTO_zalloc' function. */
#define HAVE_CRYPTO_ZALLOC 1

/* Define to 1 if you have the declaration of `UV_UDP_MMSG_CHUNK', and to 0 if
   you don't. */
#define HAVE_DECL_UV_UDP_MMSG_CHUNK 0

/* Define to 1 if you have the declaration of `UV_UDP_MMSG_FREE', and to 0 if
   you don't. */
#define HAVE_DECL_UV_UDP_MMSG_FREE 0

/* Define to 1 if you have the declaration of `UV_UDP_RECVMMSG', and to 0 if
   you don't. */
#define HAVE_DECL_UV_UDP_RECVMMSG 0

/* Define to 1 if you have the `EVP_CIPHER_CTX_free' function. */
#define HAVE_EVP_CIPHER_CTX_FREE 1

/* Define to 1 if you have the `EVP_CIPHER_CTX_new' function. */
#define HAVE_EVP_CIPHER_CTX_NEW 1

/* Define to 1 if you have the `EVP_MD_CTX_free' function. */
#define HAVE_EVP_MD_CTX_FREE 1

/* Define to 1 if you have the `EVP_MD_CTX_new' function. */
#define HAVE_EVP_MD_CTX_NEW 1

/* Define to 1 if you have the `EVP_MD_CTX_reset' function. */
#define HAVE_EVP_MD_CTX_RESET 1

/* Define to 1 if you have the `HMAC_CTX_free' function. */
#define HAVE_HMAC_CTX_FREE 1

/* Define to 1 if you have the `HMAC_CTX_get_md' function. */
#define HAVE_HMAC_CTX_GET_MD 1

/* Define to 1 if you have the `HMAC_CTX_new' function. */
#define HAVE_HMAC_CTX_NEW 1

/* Define to 1 if you have the `HMAC_CTX_reset' function. */
#define HAVE_HMAC_CTX_RESET 1

/* Define to 1 if you have the `SSL_read_ex' function. */
#define HAVE_SSL_READ_EX 1

/* Define to 1 if you have the `SSL_peek_ex' function. */
#define HAVE_SSL_PEEK_EX 1

/* Define to 1 if you have the `SSL_write_ex' function. */
#define HAVE_SSL_WRITE_EX 1

/* Define to 1 if you have the `BIO_read_ex' function. */
#define HAVE_BIO_READ_EX 1

/* Define to 1 if you have the `BIO_write_ex' function. */
#define HAVE_BIO_WRITE_EX 1

/* Define to 1 if you have the `BN_GENCB_new' function. */
#define HAVE_BN_GENCB_NEW 1

/* Define to 1 if you have the `OPENSSL_init_crypto' function. */
#define HAVE_OPENSSL_INIT_CRYPTO 1

/* Define to 1 if you have the `OPENSSL_init_ssl' function. */
#define HAVE_OPENSSL_INIT_SSL 1

/* Define to 1 if you have the `TLS_client_method' function. */
#define HAVE_TLS_CLIENT_METHOD 1

/* Define to 1 if you have the `TLS_server_method' function. */
#define HAVE_TLS_SERVER_METHOD 1

/* Define to 1 if you have the `SSL_CTX_up_ref' function. */
#define SSL_CTX_UP_REF 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/*
 * Define to nothing if C supports flexible array members, and to 1 if it does
 * not. That way, with a declaration like `struct s { int n; double
 * d[FLEXIBLE_ARRAY_MEMBER]; };', the struct hack can be used with pre-C99
 * compilers. When computing the size of such an object, don't use 'sizeof
 * (struct s)' as it overestimates the size. Use 'offsetof (struct s, d)'
 * instead. Don't use 'offsetof (struct s, d[0])', as this doesn't work with
 * MSVC and with C++ compilers.
 */
#define FLEXIBLE_ARRAY_MEMBER /**/

/* Avoid warnings with strlen() */
#ifdef _WIN64
#define strlen(x)	(unsigned int) strlen(x)
#endif

/* Get SRCID */
#include "srcid.h"

#define CKR_LIBRARY_ALREADY_INITIALIZED		0x000000FD
#define CKR_LIBRARY_FAILED_TO_LOAD		0x000000FE
#define CKR_SYMBOL_RESOLUTION_FAILED		0x000000FF