/*
   Init VFS plugins.

   Copyright (C) 2011 The Free Software Foundation, Inc.

   Written by:
   Slava Zanko <slavazanko@gmail.com>, 2011.

   This file is part of the Midnight Commander.

   The Midnight Commander is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Midnight Commander is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
 */

/** \file
 *  \brief This is a template file (here goes brief description).
 *  \author Author1
 *  \author Author2
 *  \date 20xx
 *
 *  Detailed description.
 */

#include <config.h>

#include "lib/global.h"

#include "local/local.h"

#ifdef ENABLE_VFS_CPIO
#include "cpio/cpio.h"
#endif

#ifdef ENABLE_VFS_EXTFS
#include "extfs/extfs.h"
#endif

#ifdef ENABLE_VFS_FISH
#include "fish/fish.h"
#endif

#ifdef ENABLE_VFS_FTP
#include "ftpfs/ftpfs.h"
#endif

#ifdef ENABLE_VFS_SFS
#include "sfs/sfs.h"
#endif

#ifdef ENABLE_VFS_SMB
#include "smbfs/smbfs.h"
#endif

#ifdef ENABLE_VFS_TAR
#include "tar/tar.h"
#endif

#ifdef ENABLE_VFS_UNDELFS
#include "undelfs/undelfs.h"
#endif

#include "plugins_init.h"

/*** global variables ****************************************************************************/

/*** file scope macro definitions ****************************************************************/

/*** file scope type declarations ****************************************************************/

/*** file scope variables ************************************************************************/

/*** file scope functions ************************************************************************/
/* --------------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------------- */
/*** public functions ****************************************************************************/
/* --------------------------------------------------------------------------------------------- */

void
vfs_plugins_init(void)
{
    /* localfs needs to be the first one */
    init_localfs ();

#ifdef ENABLE_VFS_CPIO
    init_cpiofs ();
#endif /* ENABLE_VFS_CPIO */
#ifdef ENABLE_VFS_TAR
    init_tarfs ();
#endif /* ENABLE_VFS_TAR */
#ifdef ENABLE_VFS_SFS
    init_sfs ();
#endif /* ENABLE_VFS_SFS */
#ifdef ENABLE_VFS_EXTFS
    init_extfs ();
#endif /* ENABLE_VFS_EXTFS */
#ifdef ENABLE_VFS_UNDELFS
    init_undelfs ();
#endif /* ENABLE_VFS_UNDELFS */

#ifdef ENABLE_VFS_FTP
    init_ftpfs ();
#endif /* ENABLE_VFS_FTP */
#ifdef ENABLE_VFS_FISH
    init_fish ();
#endif /* ENABLE_VFS_FISH */
#ifdef ENABLE_VFS_SMB
    init_smbfs ();
#endif /* ENABLE_VFS_SMB */

}

/* --------------------------------------------------------------------------------------------- */