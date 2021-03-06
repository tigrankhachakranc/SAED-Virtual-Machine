#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H


#include "disparser.h"
#include "codegenerator.h"

#include <QString>

class CDisAssembler
{
public:
	CDisAssembler();
	void work(QString exename, QString txtname);

private:
	CReaderWriter * m_rw;
	CDisParser* m_disp;
	CCodeGenerator* m_codegen;

};

#endif
