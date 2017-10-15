#include "LogFileManager.h"

const string LogFileManager::FILE_NAME = "registro_eventos.txt";

void LogFileManager::logDetect(DateTime* dt, string videoName) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		ofs << endl << "[" + generateTimeStamp(dt) + "] Inicio de detecci�n sobre alfombra. Video: " + videoName;
	}
	
	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}

void LogFileManager::logDetectStop(DateTime* dt) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		ofs << endl << "[" + generateTimeStamp(dt) + "] Fin de detecci�n sobre alfombra";
	}

	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}

string LogFileManager::generateTimeStamp(DateTime* dt) const
{
	string salida = "" + dt->getYear();
	salida += +"-" + dt->getMonth();
	salida += "-" + dt->getDay();
	salida += " " + dt->getHour();
	salida += ":" + dt->getMinute();
	salida += ":" + dt->getSecond();

	return salida;
}