// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->XOnline.1.0.4627.inl
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************

// ******************************************************************
// * XNetStartup
// ******************************************************************
OOVPA_NO_XREF(XNetStartup_1_0_5344, 8)

        { 0x01, 0xC0 },
        { 0x04, 0x50 },
        { 0x07, 0x24 },
        { 0x0A, 0x68 },
        { 0x0F, 0xE8 },
        { 0x14, 0xC2 },
        { 0x15, 0x04 },
        { 0x16, 0x00 },
OOVPA_END;

// ******************************************************************
// * XNetGetEthernetLinkStatus
// ******************************************************************
OOVPA_NO_XREF(XNetGetEthernetLinkStatus_1_0_5344, 8)

        { 0x08, 0x33 },
        { 0x10, 0x8A },
        { 0x19, 0x00 },
        { 0x22, 0x56 },
        { 0x2B, 0xFF },
        { 0x34, 0xF0 },
        { 0x3D, 0x24 },
        { 0x46, 0x5B },
OOVPA_END;

// ******************************************************************
// * CXo::XOnlineLogon
// ******************************************************************
OOVPA_XREF(CXo_XOnlineLogon_1_0_5344, 8, XREF_CXo_XOnlineLogon, XRefZero)
        { 0x21, 0xA8 },
        { 0x3E, 0x80 },
        { 0x5E, 0x00 },
        { 0x7E, 0x04 },
        { 0xA2, 0x85 },
        { 0xBE, 0xEC },
        { 0xDE, 0xF9 },
        { 0xFE, 0x33 },
OOVPA_END;

// ******************************************************************
// * XOnlineLogon
// ******************************************************************
OOVPA_XREF(XOnlineLogon_1_0_5344, 8,

    XRefNoSaveIndex,
    XRefOne)

        { 0x0B, XREF_CXo_XOnlineLogon },

        { 0x00, 0x55 },
        { 0x01, 0x8B },
        { 0x02, 0xEC },
        { 0x03, 0x5D },
        { 0x04, 0x8B },
        { 0x05, 0x0D },
        { 0x0A, 0xE9 },
OOVPA_END;

// ******************************************************************
// * XOnline_1_0_4627
// ******************************************************************
OOVPATable XOnline_1_0_5233[] = {

    // XNetStartup
	OOVPA_TABLE_PATCH(XNetStartup_1_0_5344, XTL::EmuXNetStartup),
	// WSAStartup (* unchanged since 4361 *)
	OOVPA_TABLE_PATCH(WSAStartup_1_0_4361, XTL::EmuWSAStartup),
    // XnInit (XREF) (* unchanged since 4627 *)
	OOVPA_TABLE_XREF(XnInit_1_0_4627),
	// socket
    /*
	OOVPA_TABLE_PATCH(socket_1_0_4361, MFPtoFP<XTL::EmuThis>(XTL::EmuThis::Emusocket)),
	*/
    // bind (* unchanged since 4361 *)
	OOVPA_TABLE_PATCH(bind_1_0_4361, MFPtoFP<XTL::EmuThis>(&XTL::EmuThis::Emubind)),
	// listen
    /*
	OOVPA_TABLE_PATCH(listen_1_0_4361, MFPtoFP<XTL::EmuThis>(XTL::EmuThis::Emulisten)),
	*/
    // ioctlsocket (* unchanged since 4361 *)
	OOVPA_TABLE_PATCH(ioctlsocket_1_0_4361, MFPtoFP<XTL::EmuThis>(&XTL::EmuThis::Emuioctlsocket)),
	// XNetGetEthernetLinkStatus
	OOVPA_TABLE_PATCH(XNetGetEthernetLinkStatus_1_0_5344, XTL::EmuXNetGetEthernetLinkStatus),
	// CXo::XOnlineLogon (XREF)
	OOVPA_TABLE_XREF(CXo_XOnlineLogon_1_0_5344),
	// XOnlineLogon
	OOVPA_TABLE_PATCH(XOnlineLogon_1_0_5344, XTL::EmuXOnlineLogon),
};

// ******************************************************************
// * XOnline_1_0_5233_SIZE
// ******************************************************************
uint32 XOnline_1_0_5233_SIZE = sizeof(XOnline_1_0_5233);
