/*-
 * libCCK - Clock Construction Kit
 *
 * Copyright (c) 2014 Wojciech Owczarek,
 *
 * All Rights Reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/**
 * @file   cck_transport_null.c
 * 
 * @brief  libCCK null transport implementation
 *
 */

#include "cck_transport_null.h"

#define CCK_THIS_TYPE CCK_TRANSPORT_NULL

/* interface (public) method definitions */
static int     cckTransportInit (CckTransport* transport, const CckTransportConfig* config);
static int     cckTransportShutdown (void* component);
static CckBool cckTransportTestConfig (CckTransport* transport, const CckTransportConfig* config);
static int     cckTransportPushConfig (CckTransport* transport, const CckTransportConfig* config);
static void    cckTransportRefresh (CckTransport* transport);
static CckBool cckTransportHasData (CckTransport* transport);
static CckBool cckTransportIsMulticastAddress (const TransportAddress* address);
static ssize_t cckTransportSend (CckTransport* transport, CckOctet* buf, CckUInt16 size, TransportAddress* dst, CckTimestamp* timestamp);
static ssize_t cckTransportRecv (CckTransport* transport, CckOctet* buf, CckUInt16 size, TransportAddress* src, CckTimestamp* timestamp, int flags);
static CckBool cckTransportAddressFromString (const char*, TransportAddress* out);
static char*    cckTransportAddressToString (const TransportAddress* address);
static CckBool cckTransportAddressEqual (const TransportAddress* a, const TransportAddress* b);

/* private method definitions (if any) */

/* implementations follow */

void
cckTransportSetup_null(CckTransport* transport)
{
	if(transport->transportType == CCK_THIS_TYPE) {

            transport->aclType = CCK_ACL_NULL;

	    transport->unicastCallback = NULL;
	    transport->init = cckTransportInit;
	    transport->shutdown = cckTransportShutdown;
	    transport->header.shutdown = cckTransportShutdown;
	    transport->testConfig = cckTransportTestConfig;
	    transport->pushConfig = cckTransportPushConfig;
	    transport->refresh = cckTransportRefresh;
	    transport->hasData = cckTransportHasData;
	    transport->isMulticastAddress = cckTransportIsMulticastAddress;
	    transport->send = cckTransportSend;
	    transport->recv = cckTransportRecv;
	    transport->addressFromString = cckTransportAddressFromString;
	    transport->addressToString = cckTransportAddressToString;
	    transport->addressEqual = cckTransportAddressEqual;
	} else {
	    CCK_WARNING("setup() called for incorrect transport: %02x, expected %02x\n",
			transport->transportType, CCK_THIS_TYPE);
	}
}

static int
cckTransportInit (CckTransport* transport, const CckTransportConfig* config)
{
    return 1;
}

static int
cckTransportShutdown (void* transport)
{

    return 0;

}

static CckBool
cckTransportTestConfig (CckTransport* transport, const CckTransportConfig* config)
{

    return CCK_TRUE;

}

static int
cckTransportPushConfig (CckTransport* transport, const CckTransportConfig* config)
{

    return 1;

}

static void
cckTransportRefresh (CckTransport* transport)
{

    return;

}

static CckBool
cckTransportHasData (CckTransport* transport)
{

    return CCK_FALSE;

}

static CckBool
cckTransportIsMulticastAddress (const TransportAddress* address)
{

    return CCK_FALSE;

}

static ssize_t
cckTransportSend (CckTransport* transport, CckOctet* buf, CckUInt16 size,
			TransportAddress* dst, CckTimestamp* timestamp)
{

    return 0;

}

static ssize_t
cckTransportRecv (CckTransport* transport, CckOctet* buf, CckUInt16 size,
			TransportAddress* src, CckTimestamp* timestamp, int flags)
{

    return 0;

}

static CckBool
cckTransportAddressFromString (const char* addrStr, TransportAddress* out)
{
    return CCK_TRUE;
}

static char*
cckTransportAddressToString (const TransportAddress* address)
{
    return "-";
}

static CckBool
cckTransportAddressEqual (const TransportAddress* a, const TransportAddress* b)
{

    return CCK_TRUE;

}

#undef CCK_THIS_TYPE