#!/usr/bin/env bash
# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

RunTest mesh_transport_unicast transport_tx_unicast transport_rx_unicast

conf=prj_mesh1d1_conf
RunTest mesh_transport_unicast transport_tx_unicast transport_rx_unicast
