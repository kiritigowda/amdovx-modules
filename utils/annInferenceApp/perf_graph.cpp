#include "perf_graph.h"
#include "ui_perf_graph.h"

perf_graph::perf_graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::perf_graph)
{
    ui->setupUi(this);
    maxFPS = 0;
    ui->GPU_control_lcdNumber->display(1);
    ui->GPU_horizontalSlider->setValue(1);
    ui->CPU_control_lcdNumber->display(1);
    ui->CPU_horizontalSlider->setValue(1);
    connect(ui->close_pushButton, &QAbstractButton::clicked, this, &perf_graph::closePerformanceView);
    connect(ui->reset_pushButton, &QAbstractButton::clicked, this, &perf_graph::resetPerformanceView);
    connect(ui->GPU_horizontalSlider, &QSlider::actionTriggered, this , &perf_graph::GPU_dial_ValueChanged);
    connect(ui->CPU_horizontalSlider, &QSlider::actionTriggered, this , &perf_graph::CPU_dial_ValueChanged);
}

perf_graph::~perf_graph()
{
    delete ui;
}
void perf_graph::closePerformanceView()
{
   this->close();
}
void perf_graph::setModelName(QString ModelName)
{
   ui->modelName_label->setText(ModelName);
}
void perf_graph::setStartTime(QString startTime)
{
   ui->StartTime_label->setText(startTime);
}
void perf_graph::updateElapsedTime(QString elapsedTime)
{
   ui->elapsedTime_label->setText(elapsedTime);
}
void perf_graph::setGPUName(QString GPUName)
{
   ui->GPUName_label->setText(GPUName);
}
void perf_graph::setNumGPU(int numGPU)
{
   ui->GPU_lcdNumber->display(numGPU);
   ui->GPU_horizontalSlider->setMaximum(numGPU);
}
void perf_graph::setCPUName(QString CPUName)
{
   ui->CPUName_label->setText(CPUName);
}
void perf_graph::setNumCPU(int numCPU)
{
   ui->CPU_lcdNumber->display(numCPU);
   ui->CPU_horizontalSlider->setMaximum(numCPU+1);
}
void perf_graph::resetPerformanceView()
{
    ui->fps_lcdNumber->display(0);
    ui->images_lcdNumber->display(0);
}
void perf_graph::updateFPSValue(float fps)
{
    fps = int(fps);
    ui->fps_lcdNumber->display(fps);

    if(maxFPS < fps){
        maxFPS = fps;
        ui->maxFPS_lcdNumber->display(maxFPS);
    }
}
void perf_graph::updateTotalImagesValue(int images)
{
    ui->images_lcdNumber->display(images);
}
void perf_graph::GPU_dial_ValueChanged()
{
    int dialValue = ui->GPU_horizontalSlider->value();
    ui->GPU_control_lcdNumber->display(dialValue);
}
void perf_graph::CPU_dial_ValueChanged()
{
    int dialValue = ui->CPU_horizontalSlider->value();
    ui->CPU_control_lcdNumber->display(dialValue);
}
