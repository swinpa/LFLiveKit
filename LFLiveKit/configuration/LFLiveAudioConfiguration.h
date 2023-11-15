//
//  LFLiveAudioConfiguration.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 音频码率 (也叫比特率，默认96Kbps)
 * 码率就是音频文件或者音频流中1秒中的数据量，如1.44Mbps，就是1秒钟内的数据量达1.44Mbits。
 * 音频码率 = 采样率*位深*声道数目，比如CD的就是44100*16*2=1411kbps。
 * 位深：一个采样点数据用几位表示，一般有8位，16位，也可以是24位
 */
typedef NS_ENUM (NSUInteger, LFLiveAudioBitRate) {
    /// 32Kbps 音频码率
    LFLiveAudioBitRate_32Kbps = 32000,
    /// 64Kbps 音频码率
    LFLiveAudioBitRate_64Kbps = 64000,
    /// 96Kbps 音频码率
    LFLiveAudioBitRate_96Kbps = 96000,
    /// 128Kbps 音频码率
    LFLiveAudioBitRate_128Kbps = 128000,
    /// 默认音频码率，默认为 96Kbps
    LFLiveAudioBitRate_Default = LFLiveAudioBitRate_96Kbps
};

/**
 * 参考：https://zhuanlan.zhihu.com/p/576265735
 * 音频采样率 (默认44.1KHz)
 * 采样率，就是每秒对声音进行采集的次数
 * 
 * 采样率是指将声音（模拟信号）转换成mp3（数字信号）时的采样频率，也就是单位时间内采样多少点数据。（一个采样点数据有8位，16位，也可以是24位)
 * 音频中叫采样率，是指把音频信号数字化（AD采样）后一个通道1秒钟有多少个样本，对应而来的就是原始的数据。如44.1kHz的采样率，就是指1个
 * 通道1秒钟有44.1k个数据，这数据可以是16位，也可以是24或者其他，这就是采样精度。
 *
 * 简单地说就是通过波形采样的方法记录1秒钟长度的声音，需要多少个数据点。
 * 采样频率一般共分为22.05KHz、44.1KHz、48KHz三个等级；
 * 22.05KHz表示1秒钟有22.05K个数据点，该等级只能达到FM广播的声音品质，
 * 44.1KHz表示1秒钟有44.1K个数据点，该等级是理论上的CD音质界限，
 * 48KHz表示1秒钟有48K个数据点，该等级已达到DVD音质了。
 */
typedef NS_ENUM (NSUInteger, LFLiveAudioSampleRate){
    /// 16KHz 采样率
    LFLiveAudioSampleRate_16000Hz = 16000,
    /// 44.1KHz 采样率的声音就是要花费44000个数据点来描述1秒钟的声音波形。
    LFLiveAudioSampleRate_44100Hz = 44100,
    /// 48KHz 采样率
    LFLiveAudioSampleRate_48000Hz = 48000,
    /// 默认音频采样率，默认为 44.1KHz
    LFLiveAudioSampleRate_Default = LFLiveAudioSampleRate_44100Hz
};

///  Audio Live quality（音频质量）
typedef NS_ENUM (NSUInteger, LFLiveAudioQuality){
    /// 低音频质量 audio sample rate: 16KHz audio bitrate: numberOfChannels 1 : 32Kbps  2 : 64Kbps
    LFLiveAudioQuality_Low = 0,
    /// 中音频质量 audio sample rate: 44.1KHz audio bitrate: 96Kbps
    LFLiveAudioQuality_Medium = 1,
    /// 高音频质量 audio sample rate: 44.1MHz audio bitrate: 128Kbps
    LFLiveAudioQuality_High = 2,
    /// 超高音频质量 audio sample rate: 48KHz, audio bitrate: 128Kbps
    LFLiveAudioQuality_VeryHigh = 3,
    /// 默认音频质量 audio sample rate: 44.1KHz, audio bitrate: 96Kbps
    LFLiveAudioQuality_Default = LFLiveAudioQuality_High
};

@interface LFLiveAudioConfiguration : NSObject<NSCoding, NSCopying>

/// 默认音频配置
+ (instancetype)defaultConfiguration;
/// 音频配置
+ (instancetype)defaultConfigurationForQuality:(LFLiveAudioQuality)audioQuality;

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/// 声道数目(default 2)
@property (nonatomic, assign) NSUInteger numberOfChannels;
/// 采样率
@property (nonatomic, assign) LFLiveAudioSampleRate audioSampleRate;
/// 码率
@property (nonatomic, assign) LFLiveAudioBitRate audioBitrate;
/// flv编码音频头 44100 为0x12 0x10
@property (nonatomic, assign, readonly) char *asc;
/// 缓存区长度
@property (nonatomic, assign,readonly) NSUInteger bufferLength;

@end
