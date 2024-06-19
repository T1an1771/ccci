/*
*    Copyright (c) 2018 Shing Liu All Rights Reserved.
*
*           File : occQt.h
*         Author : Shing Liu(eryar@163.com)
*           Date : 2018-01-08 20:00
*        Version : OpenCASCADE7.2.0 & Qt5.7.1
*
*    Description : OpenCASCADE in Qt.
*/

#ifndef OCCQT_H
#define OCCQT_H


#include <AIS_Shape.hxx>
#include <AIS_Trihedron.hxx>
#include "ui_occQt.h"

#include <AIS_InteractiveContext.hxx>
#include <QLabel>
#include <QStandardItem>
#include <QTreeView>
#include<TopoDS.hxx>
#include <vector>
using namespace std;
class OccView;
class SlicingSettingWidget;

//! Qt main window which include OpenCASCADE for its central widget.
class occQt : public QMainWindow
{
    Q_OBJECT

public:
    //! constructor/destructor.
    occQt(QWidget *parent = nullptr);
    ~occQt();

    Handle_AIS_Trihedron m_aisOriginTrihedron;

    static void WireOffSetTest(TopoDS_Wire&faceWire);

protected:

    void deleteElderShape(Handle(AIS_InteractiveContext)&context);

    //! create all the actions.
    void creatActions(void);

    //! create all the menus.
    void creatMenus(void);

    //! create the toolbar.
    void creatToolBars(void);

    //! make cylindrical helix.
    void makeCylindricalHelix(void);

    //! make conical helix.
    void makeConicalHelix(void);

    //! make toroidal helix.
    void makeToroidalHelix(void);


private slots:
    void deleteShapes(Handle(AIS_InteractiveContext)&context);

    //! show about box.
    void about(void);

    //! show SlicingSettingToolBar
    void showSlicingSettingWidget(void);

    //! make box test.
    void makeBox(void);

    //! make cone test.
    void makeCone(void);

    //! make sphere test.
    void makeSphere(void);

    //! make cylinder test.
    void makeCylinder(void);

    //! make torus test.
    void makeTorus(void);

    //! fillet test.
    void makeFillet(void);

    //! chamfer test.
    void makeChamfer(void);

    //! test extrude algorithm.
    void makeExtrude(void);

    //! test revol algorithm.
    void makeRevol(void);

    //! test loft algorithm.
    void makeLoft(void);

    //! test boolean operation cut.
    void testCut(void);

    //! test boolean operation fuse.
    void testFuse(void);

    //! test boolean operation common.
    void testCommon(void);

    //! test helix shapes.
    void testHelix(void);

    //!read igs
    void readIGS();

    //!read step
    void readSTEP_FACE();
    void readSTEP_SOLID();
public:
    SlicingSettingWidget * Widget1;
private:
    //friend class SlicingSettingWidget;
    Ui::occQtClass ui;
    OccView* myOccView;
    QToolButton *selectButton;
    QTreeView*treeView;

};

#endif // OCCQT_H
