#!/bin/sh

# Copyright (C) Internet Systems Consortium, Inc. ("ISC")
#
# SPDX-License-Identifier: MPL-2.0
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0.  If a copy of the MPL was not distributed with this
# file, you can obtain one at https://mozilla.org/MPL/2.0/.
#
# See the COPYRIGHT file distributed with this work for additional
# information regarding copyright ownership.

rm -f */named.conf */named.memstats */ans.run */named.recursing */named.run
rm -f ans4/norespond
rm -f burst.input.*
rm -f dig.out*
rm -f ns*/managed-keys.bind*
rm -f ns3/named.stats ns3/named.stats.prev ns3/named_dump.db
