

#include <ncnn/net.h>
#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QPushButton>
#include <QSharedMemory>
#include <iostream>
#include <cstring>
#include "AIBackend/YoloEngine.h"
#include <windows.h>
#include "UI/FPSHelperWindow.h"
#include <QStyleFactory>
#include "Control/ControlModel.h"
#include <QMessageBox>
using namespace std;

ControlModel model;
bool isProcessRunAsAdmin()
{
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;
    BOOL b = AllocateAndInitializeSid(
            &NtAuthority,
            2,
            SECURITY_BUILTIN_DOMAIN_RID,
            DOMAIN_ALIAS_RID_ADMINS,
            0, 0, 0, 0, 0, 0,
            &AdministratorsGroup);
    if(b)
    {
        CheckTokenMembership(NULL, AdministratorsGroup, &b);
        FreeSid(AdministratorsGroup);
    }
    return b == TRUE;
}
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    Ui::FPSHelperWindow window(nullptr, model.getControlInterface(ControlModel::CONTROLLER_TYPE_UI));
    window.show();
    if(!isProcessRunAsAdmin()){
        QMessageBox::critical(&window,"Error","Administrative permission required! "
                                              "\nPlease run this program in administrative mode !",
                              QMessageBox::Ok);
        return 0;
    }
    return app.exec();
}
