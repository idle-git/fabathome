/*License Notification
Fab@Home operates under the BSD Open Source License

Copyright (c) 2006, Hod Lipson and Evan Malone (evan.malone@cornell.edu) All rights reserved. 

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met: 

Redistributions of source code must retain the above copyright notice, 
this list of conditions and the following disclaimer. 
Redistributions in binary form must reproduce the above copyright notice, 
this list of conditions and the following disclaimer in the documentation and/or 
other materials provided with the distribution. 
Neither the name of the Fab@Home Project nor the names of its contributors may be 
used to endorse or promote products derived from this software without specific 
prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "StdAfx.h"
#include ".\startpacket.h"

IMPLEMENT_DYNAMIC(CStartPacket, CPacket)

CStartPacket::CStartPacket(void)
{
}

CStartPacket::~CStartPacket(void)
{
}

bool CStartPacket::InitPacket(void)
{
	//call the base class Init fn FIRST!!!!
	//it fills in the packet code, so we need to overwrite it afterward
	if(!CPacket::InitPacket()) return false;

	//always remember to overwrite the packet type
	m_enumPktCode = START;

	return true;
}

bool CStartPacket::PacketToStream(BYTE *buf, unsigned int *size)
{
	//convert the packet into a stream of bytes
	//return a stream of bytes in *buf, and true if successful
	//*size should pass in the maximum space available in the buffer
	//and will be used to return the number of bytes written
	if( (buf == NULL) || (size == NULL) || (*size < m_bytePktSize) )
		return false;

	//call the base class PacketToStream to handle the common members
	unsigned int cnt = *size;
	if(!CPacket::PacketToStream(buf,&cnt))
		return false;

	//now fill in the derived class members
	//none for start packet

	if(cnt > *size) return false;
	*size = cnt;

	return true;
}

bool CStartPacket::StreamToPacket(BYTE *buf, unsigned int *size)
{
	//convert a stream of bytes into a packet
	//read data from *buf as a stream of bytes
	//*size should pass in the length of the data in the buffer in bytes
	//and will be used to return the number of bytes read
	//return true if successful
	if( (buf == NULL) || (size == NULL) || (*size < m_bytePktSize) )
		return false;

	//call the base class StreamToPacket to handle the common members
	unsigned int cnt = *size;
	if(!CPacket::StreamToPacket(buf,&cnt))
		return false;

	//now fill in the derived class members
	//none for start packet
	if(cnt > *size) return false;
	*size = cnt;

	return true;
}