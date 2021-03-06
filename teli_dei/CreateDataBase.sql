USE [municipality]
GO

/****** Object:  Table [dbo].[dei_paroxes]    Script Date: 03/29/2017 14:12:01 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[dei_paroxes](
	[id] [int] NULL,
	[Paroxi] [int] not NULL,
	[Onomateponimo] [nvarchar](255) NULL,
	[Odos] [nvarchar](255) NULL,
	[Arithmos] [nvarchar](255) NULL,
	[Poli] [nvarchar](255) NULL,
	[TaxKodikas] [nvarchar](50) NULL,
	[KodikosDK] [nvarchar](50) NULL,
	[KodikosXreosis] [nvarchar](50) NULL,
	[KodikosApalagis] [nvarchar](50) NULL,
	[TetragonikaMetraDimTelon] [int] NULL,
	[TetragonikaMetraDimForou] [int] NULL,
	[KodikosXreosisTap] [nvarchar](50) NULL,
	[DiktisXreosisXrisisTap] [nvarchar](50) NULL,
	[KodikosApalagisTap] [nvarchar](50) NULL,
	[TetragvnikaMetraTap] [int] NULL,
	[EtosAdeias] [int]NULL,
	[KodikosZonisTap] [int] NULL,
	[OnomasiaDimou] [nvarchar](255) NULL,
	[KodikosDimou] [nvarchar](255) NULL,
	primary key [Paroxi]
) ON [PRIMARY]

GO


