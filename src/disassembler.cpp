#include "disassembler.h"

CDisassembler::CDisassembler()
{
	m_reader = new CReaderWriter();
	m_disParser = new CDisParser();
	m_codeGenerator = new CCodeGenerator();
}
void CDisassembler::work(QString sFileExe, QString sFileTxt)
{
	QByteArray buffer = m_reader->read(sFileExe);

	m_disParser->work(buffer);
	QVector<SDataToken> dataTokens = m_disParser->getDataTokens();
	QVector<SCodeToken> codeTokens = m_disParser->getCodeTokens();
	QVector<QString> sDataNames = m_disParser->getDataNames();

	m_codeGenerator -> work(dataTokens, codeTokens, sDataNames, sFileTxt);
}