CREATE TABLE GRAVADORA (
       Codigo_Gravadora		NUMBER(3) NOT NULL,
       Nome_Gravadora       VARCHAR2(60) NULL,
       Endereco             VARCHAR2(60) NULL,
       Telefone             VARCHAR2(20) NULL,
       Contato              VARCHAR2(20) NULL,
       URL                  VARCHAR2(80) NULL
);


ALTER TABLE GRAVADORA
       ADD  ( CONSTRAINT XPKGRAVADORA PRIMARY KEY (Codigo_Gravadora) ) ;


CREATE TABLE CD (
       Codigo_CD            NUMBER(5) NOT NULL,
       Codigo_Gravadora     NUMBER(3) NULL,
       Nome_CD              VARCHAR2(60) NULL,
       Preco_Venda          NUMBER(14,2) NULL,
       Data_Lancamento      DATE NULL,
       CD_Indicado          NUMBER(5) NULL
);

CREATE INDEX XIF6CD ON CD
(
       Codigo_Gravadora
);


ALTER TABLE CD
       ADD  ( CONSTRAINT XPKCD PRIMARY KEY (Codigo_CD) ) ;


CREATE TABLE MUSICA (
       Codigo_Musica        NUMBER(5) NOT NULL,
       Nome_Musica          VARCHAR2(60) NULL,
       Duracao              NUMBER(6,2) NULL
);


ALTER TABLE MUSICA
       ADD  ( CONSTRAINT XPKMUSICA PRIMARY KEY (Codigo_Musica) ) ;


CREATE TABLE AUTOR (
       Codigo_Autor         NUMBER(5) NOT NULL,
       Nome_Autor           VARCHAR2(60) NULL
);


ALTER TABLE AUTOR
       ADD  ( CONSTRAINT XPKAUTOR PRIMARY KEY (Codigo_Autor) ) ;


CREATE TABLE MUSICA_AUTOR (
       Codigo_Musica        NUMBER(5) NOT NULL,
       Codigo_Autor         NUMBER(5) NOT NULL
);

CREATE INDEX XIF11MUSICA_AUTOR ON MUSICA_AUTOR
(
       Codigo_Musica
);

CREATE INDEX XIF12MUSICA_AUTOR ON MUSICA_AUTOR
(
       Codigo_Autor
);


ALTER TABLE MUSICA_AUTOR
       ADD  ( CONSTRAINT XPKMUSICA_AUTOR PRIMARY KEY (Codigo_Musica, 
              Codigo_Autor) ) ;


CREATE TABLE FAIXA (
       Codigo_Musica        NUMBER(5) NOT NULL,
       Codigo_CD            NUMBER(5) NOT NULL,
       Numero_Faixa         NUMBER(2) NULL
);

CREATE INDEX XIF13FAIXA ON FAIXA
(
       Codigo_Musica
);

CREATE INDEX XIF14FAIXA ON FAIXA
(
       Codigo_CD
);


ALTER TABLE FAIXA
       ADD  ( CONSTRAINT XPKFAIXA PRIMARY KEY (Codigo_Musica, 
              Codigo_CD) ) ;


CREATE TABLE CD_CATEGORIA(
       Codigo_Categoria   NUMBER(2)    NOT NULL,
       Menor_Preco        NUMBER(14,2) NOT NULL,
       Maior_Preco        NUMBER(14,2) NOT NULL
);


ALTER TABLE CD
       ADD  ( CONSTRAINT GRAVADORA_CD
              FOREIGN KEY (Codigo_Gravadora)
                             REFERENCES GRAVADORA ) ;

ALTER TABLE CD
       ADD  ( CONSTRAINT CD_CD
              FOREIGN KEY (CD_Indicado)
                             REFERENCES CD ) ;

ALTER TABLE MUSICA_AUTOR
       ADD  ( CONSTRAINT AUTOR_MUSICA_AUTOR
              FOREIGN KEY (Codigo_Autor)
                             REFERENCES AUTOR ) ;


ALTER TABLE MUSICA_AUTOR
       ADD  ( CONSTRAINT MUSICA_MUSICA_AUTOR
              FOREIGN KEY (Codigo_Musica)
                             REFERENCES MUSICA ) ;


ALTER TABLE FAIXA
       ADD  ( CONSTRAINT CD_FAIXA
              FOREIGN KEY (Codigo_CD)
                             REFERENCES CD ) ;


ALTER TABLE FAIXA
       ADD  ( CONSTRAINT MUSICA_FAIXA
              FOREIGN KEY (Codigo_Musica)
                             REFERENCES MUSICA ) ;



