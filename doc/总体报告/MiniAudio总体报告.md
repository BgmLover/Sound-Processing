### MiniAudio总体报告

[TOC]

队伍成员：张清（队长），陈博强，林成楠，张立涵



#### 1．总体目标

​	本次实验是基于MVVM（Model-View-ViewModel）框架的一次C++开发实践。总体目标是实现一个带有图形界面的音频处理软件，实现对.wav等音频的添加、播放、暂停等播放器基础功能，实现对.wav音频的频率、音调的更改、音频波形图的显示等高级功能。



#### 2．系统框架

 ![7B55880F-054B-406A-8844-A4CA7107BC4E](/Users/apple/Library/Containers/com.tencent.qq/Data/Library/Application Support/QQ/Users/641119121/QQ/Temp.db/7B55880F-054B-406A-8844-A4CA7107BC4E.png)



#### 3．功能分析

以下为version1.01版本的界面与功能实现:

启动界面：  ![5FD141DE-9E2E-4C07-8CDF-D7F974E1DC2D](Sound-Processing/doc/总体报告/imageReport/before.png)

##### 3.1 音频的添加播放

点击添加音乐可以从本地添加音乐到列表中。

  ![36499BA4-EA16-4736-A759-AD686CEC5EBF](/Users/apple/Library/Containers/com.tencent.qq/Data/Library/Application Support/QQ/Users/641119121/QQ/Temp.db/36499BA4-EA16-4736-A759-AD686CEC5EBF.png)

点击菜单栏上的按钮可以实现播放、暂停、上一首／下一首等功能。

##### 3.2 音调的变化处理

点击"OK"按钮后将当前播放音频进行音调变化处理，处理完的结果保存到用户指定的路径，并自动添加到歌单。

 ![4D1AEE30-681D-4878-B079-41BE161F0B6A](/Users/apple/Library/Containers/com.tencent.qq/Data/Library/Application Support/QQ/Users/641119121/QQ/Temp.db/4D1AEE30-681D-4878-B079-41BE161F0B6A.png) 

##### 3.3 频率的变化处理

点击"OK"按钮后将当前播放音频进行频率变化处理，处理完的结果保存到用户指定的路径，并自动添加到歌单。

 ![2AF5C6B9-5D65-43FB-AAD6-F2D1665F6471](/Users/apple/Library/Containers/com.tencent.qq/Data/Library/Application Support/QQ/Users/641119121/QQ/Temp.db/2AF5C6B9-5D65-43FB-AAD6-F2D1665F6471.png) 

##### 3.4 波形图的显示

​	如3.1中图中显示。



​

​	
