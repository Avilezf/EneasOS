//
// webserver.cpp
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2015  R. Stange <rsta2@o2online.de>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include "webserver.h"
#include <circle/logger.h>
#include <circle/string.h>
#include <circle/util.h>
#include <assert.h>

#define MAX_CONTENT_SIZE	300000

// our content
static const char s_Index[] =
#include "index.h"
;

static const u8 s_Style[] = 
#include "style.h"
;

static const u8 s_LEDOff[] =
{
#include "ledoff.h"
};

static const u8 s_LEDOn[] =
{
#include "ledon.h"
};

static const u8 s_Amstrong[] =
{
#include "amstrong.h"
};
static const u8 s_Eneasintro[] =
{
#include "eneasintro.h"
};
static const u8 s_Eneasoslogo[] =
{
#include "eneasoslogo.h"
};
static const u8 s_Globallogo[] =
{
#include "globallogo.h"
};
static const u8 s_Joshua[] =
{
#include "joshua.h"
};
static const u8 s_Medalla[] =
{
#include "medalla.h"
};
static const u8 s_Mono[] =
{
#include "mono.h"
};
static const u8 s_Pipe[] =
{
#include "pipe.h"
};
static const u8 s_Premio[] =
{
#include "premio.h"
};
static const u8 s_Seguridadlogo[] =
{
#include "seguridadlogo.h"
};
static const u8 s_Servidorportable[] =
{
#include "servidorportable.h"
};
static const u8 s_Technical[] =
{
#include "technical.h"
};
static const u8 s_Trofeo[] =
{
#include "trofeo.h"
};
static const u8 s_Urbanline[] =
{
#include "urbanline.h"
};

static const char FromWebServer[] = "webserver";

CWebServer::CWebServer (CNetSubSystem *pNetSubSystem, CActLED *pActLED, CSocket *pSocket)
:	CHTTPDaemon (pNetSubSystem, pSocket, MAX_CONTENT_SIZE),
	m_pActLED (pActLED)
{
}

CWebServer::~CWebServer (void)
{
	m_pActLED = 0;
}

CHTTPDaemon *CWebServer::CreateWorker (CNetSubSystem *pNetSubSystem, CSocket *pSocket)
{
	return new CWebServer (pNetSubSystem, m_pActLED, pSocket);
}

THTTPStatus CWebServer::GetContent (const char  *pPath,
				    const char  *pParams,
				    const char  *pFormData,
				    u8	        *pBuffer,
				    unsigned    *pLength,
				    const char **ppContentType)
{
	assert (pPath != 0);
	assert (ppContentType != 0);
	assert (m_pActLED != 0);

	CString String;
	const u8 *pContent = 0;
	unsigned nLength = 0;

	if (   strcmp (pPath, "/") == 0
	    || strcmp (pPath, "/index.html") == 0)
	{
		assert (pFormData != 0);
		if (strcmp (pFormData, "actled=1") == 0)
		{
			m_pActLED->On ();

			String.Format (s_Index, "", "checked", "ledon.png");	// must match index.html
		}
		else
		{
			m_pActLED->Off ();

			String.Format (s_Index, "checked", "", "ledoff.png");
		}

		pContent = (const u8 *) (const char *) String;
		nLength = String.GetLength ();
		*ppContentType = "text/html; charset=utf-8";
	}
	else if (strcmp (pPath, "/style.css") == 0)
	{
		pContent = s_Style;
		nLength = sizeof s_Style-1;
		*ppContentType = "text/css";
	}
	else if (strcmp (pPath, "/ledoff.png") == 0)
	{
		pContent = s_LEDOff;
		nLength = sizeof s_LEDOff;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/ledon.png") == 0)
	{
		pContent = s_LEDOn;
		nLength = sizeof s_LEDOn;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/amstrong.jpeg") == 0)
	{
		pContent = s_Amstrong;
		nLength = sizeof s_Amstrong;
		*ppContentType = "image/jpeg";
	}
	else if (strcmp (pPath, "/joshua.jpeg") == 0)
	{
		pContent = s_Joshua;
		nLength = sizeof s_Joshua;
		*ppContentType = "image/jpeg";
	}
	else if (strcmp (pPath, "/pipe.jpeg") == 0)
	{
		pContent = s_Pipe;
		nLength = sizeof s_Pipe;
		*ppContentType = "image/jpeg";
	}
	else if (strcmp (pPath, "/mono.jpeg") == 0)
	{
		pContent = s_Mono;
		nLength = sizeof s_Mono;
		*ppContentType = "image/jpeg";
	}
	else if (strcmp (pPath, "/eneasintro.png") == 0)
	{
		pContent = s_Eneasintro;
		nLength = sizeof s_Eneasintro;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/eneasoslogo.png") == 0)
	{
		pContent = s_Eneasoslogo;
		nLength = sizeof s_Eneasoslogo;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/globallogo.png") == 0)
	{
		pContent = s_Globallogo;
		nLength = sizeof s_Globallogo;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/medalla.png") == 0)
	{
		pContent = s_Medalla;
		nLength = sizeof s_Medalla;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/premio.png") == 0)
	{
		pContent = s_Premio;
		nLength = sizeof s_Premio;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/seguiridadlogo.png") == 0)
	{
		pContent = s_Seguridadlogo;
		nLength = sizeof s_Seguridadlogo;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/servidorportable.png") == 0)
	{
		pContent = s_Servidorportable;
		nLength = sizeof s_Servidorportable;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/technical.png") == 0)
	{
		pContent = s_Technical;
		nLength = sizeof s_Technical;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/trofeo.png") == 0)
	{
		pContent = s_Trofeo;
		nLength = sizeof s_Trofeo;
		*ppContentType = "image/png";
	}
	else if (strcmp (pPath, "/urbanline.png") == 0)
	{
		pContent = s_Urbanline;
		nLength = sizeof s_Urbanline;
		*ppContentType = "image/png";
	}
	else
	{
		return HTTPNotFound;
	}

	assert (pLength != 0);
	if (*pLength < nLength)
	{
		CLogger::Get ()->Write (FromWebServer, LogError, "Increase MAX_CONTENT_SIZE to at least %u", nLength);

		return HTTPInternalServerError;
	}

	assert (pBuffer != 0);
	assert (pContent != 0);
	assert (nLength > 0);
	memcpy (pBuffer, pContent, nLength);

	*pLength = nLength;

	return HTTPOK;
}
