/*
 * Copyright (c) 2005-2016, BearWare.dk
 * 
 * Contact Information:
 *
 * Bjoern D. Rasmussen
 * Skanderborgvej 40 4-2
 * DK-8000 Aarhus C
 * Denmark
 * Email: contact@bearware.dk
 * Phone: +45 20 20 54 59
 * Web: http://www.bearware.dk
 *
 * This source code is part of the TeamTalk 5 Conferencing System
 * owned by BearWare.dk. Unauthorized use is prohibited. No changes
 * are allowed to this file without the copyright owner's written
 * consent. Using this file requires a source code license issued by
 * BearWare.dk.
 *
 */

#ifndef CLIENTXML_H
#define CLIENTXML_H

#include "Settings.h"

#define TEAMTALK_XML_VERSION                        "5.1"

#define TEAMTALK_XML_VERSION_DEFAULT                "5.0"

#define DEFAULT_NICKNAME                            _T("NoName")
#define DEFAULT_GENDER                              1
#define DEFAULT_PUSHTOTALK                          false
#define DEFAULT_VOICEACTIVATED                      true
#define DEFAULT_VOICEACTIVATE_LEVEL                 2

#define DEFAULT_SOUND_OUTPUT_VOLUME                 50
#define DEFAULT_SOUND_GAIN_LEVEL                    50
#define DEFAULT_MEDIA_VS_VOICE                      100

namespace teamtalk {

    typedef std::vector<int> HotKey;

    struct HostEntry
    {
        std::string szEntryName;
        std::string szAddress;
        int nTcpPort;
        int nUdpPort;
        bool bEncrypted;
        std::string szUsername;
        std::string szPassword;
        std::string szChannel;
        std::string szChPasswd;

        std::string szNickname;
        int nGender;
        HotKey hotkey;
        int nVoiceAct; // < 0 = disabled
        VideoFormat capformat;
        VideoCodec vidcodec;

        HostEntry()
        : nTcpPort(0)
        , nUdpPort(0)
        , bEncrypted(FALSE)
        , nGender(0)
        , nVoiceAct(-1)
        , capformat()
        , vidcodec() { }
    };

    //used for join channel
    struct JoinChannel
    {
        std::string szChannelPath;
        std::string szPassword;
        std::string szTopic;
        std::string szOpPasswd;
    };


    class ClientXML : public XMLDocument
    {
    public:
        ClientXML(const std::string& rootname) : XMLDocument(rootname, TEAMTALK_XML_VERSION){}

        /******** <main> ********/
        bool SetWindowPlacement(int x, int y, int cx, int cy);
        bool GetWindowPlacement(int& x, int& y, int& cx, int& cy);

        bool SetWindowExtended(bool bExtended);
        bool GetWindowExtended();

        /******** </main> ********/

        /******** <general> *******/
        bool SetNickname(std::string szNickname);
        std::string GetNickname(std::string def_nickname = std::string());

        bool SetGender(int nGender);
        int GetGender(int nDefGender = DEFAULT_GENDER);

        bool SetPushToTalk(bool bEnable);
        bool GetPushToTalk(bool bDefEnable = DEFAULT_PUSHTOTALK);

        bool SetPushToTalkKey(const HotKey& keykey);
        bool GetPushToTalkKey(HotKey& hotkey);

        bool SetVoiceActivated(bool bEnable);
        bool GetVoiceActivated(bool bDefVoiceAct = DEFAULT_VOICEACTIVATED);

        bool SetVoiceActivationLevel(int nLevel);
        int GetVoiceActivationLevel(int nDefVoxLevel = DEFAULT_VOICEACTIVATE_LEVEL);

        int SetInactivityDelay(int nDelay);
        int GetInactivityDelay();

        bool SetDisableVadOnIdle(bool bEnable);
        bool GetDisableVadOnIdle();

        bool SetDesktopShareMode(int nMode);
        int GetDesktopShareMode();

        bool SetDesktopShareRgbMode(int nMode);
        int GetDesktopShareRgbMode();

        bool SetDesktopShareUpdateInterval(int nInterval);
        int GetDesktopShareUpdateInterval();

        bool SetFirewallInstall(bool bAsked);
        bool GetFirewallInstall(bool bDefValue);
        /******** </general> *******/

        /******** <window> ********/
        bool SetFont(std::string szFontName, int nSize, bool bBold, bool bUnderline, bool bItalic);
        bool GetFont(std::string& szFontName, int& nSize, bool& bBold, bool& bUnderline, bool& bItalic);

        bool SetStartMinimized(bool bEnable);
        bool GetStartMinimized();

        bool SetMinimizeToTray(bool bEnable);
        bool GetMinimizeToTray();

        bool SetPopupOnMessage(bool bEnable);
        bool GetPopupOnMessage();

        bool SetAlwaysOnTop(bool bEnable);
        bool GetAlwaysOnTop();

        bool SetShowUserCount(bool bEnable);
        bool GetShowUserCount();

        bool SetJoinDoubleClick(bool bEnable);
        bool GetJoinDoubleClick();

        bool SetQuitClearChannels(bool bEnable);
        bool GetQuitClearChannels();

        bool SetMessageTimeStamp(bool bEnable);
        bool GetMessageTimeStamp();

        bool SetLanguageFile(std::string szLanguageFile);
        std::string GetLanguageFile();

        bool SetCloseTransferDialog(bool bEnable);
        bool GetCloseTransferDialog();

        bool SetVuMeterUpdate(bool bEnable);
        bool GetVuMeterUpdate();

        bool SetCheckApplicationUpdates(bool bEnable);
        bool GetCheckApplicationUpdates();

        bool SetShowUsernames(bool bEnable);
        bool GetShowUsernames();

        bool SetMaxTextLength(int nLength);
        int GetMaxTextLength(int nDefault);

        bool SetShowPublicServers(bool bEnable);
        bool GetShowPublicServers();

        /******** </window> *******/


        /******** <client> *********/
        bool SetClientTcpPort(int nPort);
        int GetClientTcpPort(int nDefPort);

        bool SetClientUdpPort(int nPort);
        int GetClientUdpPort(int nDefPort);

        bool SetAutoConnectToLastest(bool bEnable);
        bool GetAutoConnectToLastest();

        bool SetReconnectOnDropped(bool bEnable);
        bool GetReconnectOnDropped();

        bool SetAutoJoinRootChannel(bool bEnable);
        bool GetAutoJoinRootChannel();

        bool SetAudioLogStorageFormat(int aff);
        int GetAudioLogStorageFormat();

        bool SetAudioLogStorageMode(int mode);
        int GetAudioLogStorageMode();

        bool SetAudioLogStorage(const std::string& audiofolder);
        std::string GetAudioLogStorage();

        bool SetChanTextLogStorage(const std::string& audiofolder);
        std::string GetChanTextLogStorage();

        bool SetUserTextLogStorage(const std::string& audiofolder);
        std::string GetUserTextLogStorage();

        bool SetDefaultSubscriptions(int subs);
        int GetDefaultSubscriptions();
        /********* </client> ********/

        /********* <soundsystem> ********/
        bool SetSoundInputDevice(int nDevice);
        int GetSoundInputDevice(int nDefDeviceId);

        bool SetSoundInputDevice(const std::string& devid);
        std::string GetSoundInputDevice();

        bool SetSoundOutputDevice(int nDevice);
        int GetSoundOutputDevice(int nDefDeviceId);

        bool SetSoundOutputDevice(const std::string& devid);
        std::string GetSoundOutputDevice();

        bool SetSoundOutputVolume(int nVolume);
        int GetSoundOutputVolume(int def_vol);

        bool SetMediaStreamVsVoice(int nPercent);
        int GetMediaStreamVsVoice(int nDefPercent);

        bool SetSoundMixerDevice(int nDevice);
        int GetSoundMixerDevice();

        bool SetAutoPositioning(bool bEnable);
        bool GetAutoPositioning();

        bool SetAGC(bool bEnable);
        bool GetAGC(bool bDefValue);

        bool SetDenoise(bool bEnable);
        bool GetDenoise(bool bDefValue);

        bool SetVoiceGain(bool bEnable);
        bool GetVoiceGain();

        bool SetVoiceGainLevel(int nGain);
        int GetVoiceGainLevel(int nDefGain);

        bool SetDuplexMode(bool bEnable);
        bool GetDuplexMode(bool bDefValue);

        bool SetEchoCancel(bool bEnable);
        bool GetEchoCancel(bool bDefValue);
        /********* </soundsystem> ********/

        /********* <events> *************/
        bool SetEventNewUser(std::string szPath);
        std::string GetEventNewUser();

        bool SetEventNewMessage(std::string szPath);
        std::string GetEventNewMessage();

        bool SetEventRemovedUser(std::string szPath);
        std::string GetEventRemovedUser();

        bool SetEventServerLost(std::string szPath);
        std::string GetEventServerLost();

        bool SetEventUserReturned(std::string szPath);
        std::string GetEventUserReturned();

        bool SetEventUserStoppedTalking(std::string szPath);
        std::string GetEventUserStoppedTalking();

        bool SetEventHotKey(std::string szPath);
        std::string GetEventHotKey();

        bool SetEventChannelMsg(std::string szPath);
        std::string GetEventChannelMsg();

        bool SetEventFilesUpd(std::string szPath);
        std::string GetEventFilesUpd();

        bool SetEventTransferEnd(std::string szPath);
        std::string GetEventTransferEnd();

        bool SetEventVideoSession(std::string szPath);
        std::string GetEventVideoSession();

        bool SetEventDesktopSession(std::string szPath);
        std::string GetEventDesktopSession();

        bool SetEventQuestionMode(std::string szPath);
        std::string GetEventQuestionMode();

        bool SetEventDesktopAccessReq(std::string szPath);
        std::string GetEventDesktopAccessReq();

        bool SetEventVibrateOnMsg(int nIndex);
        int GetEventVibrateOnMsg();

        bool SetEventFlashOnMsg(int nIndex);
        int GetEventFlashOnMsg();

        bool SetEventTTSEvents(TTSEvents uEvents);
        TTSEvents GetEventTTSEvents();
        /********* </events> ************/

        /********* <advanced> ***********/
        bool SetMixerAutoSelection(bool bEnable);
        bool GetMixerAutoSelection();

        bool SetMixerAutoSelectInput(int nIndex);
        int GetMixerAutoSelectInput();

        bool SetMixerBoostBugCompensation(bool bEnable);
        bool GetMixerBoostBugCompensation();

        bool SetLowLevelMouseHook(bool bEnable);
        bool GetLowLevelMouseHook();
        /********* </advanced> **********/

        /********* <shortcuts> **********/
        bool SetHotKeyVoiceAct(const HotKey& hotkey);
        bool GetHotKeyVoiceAct(HotKey& hotkey);

        bool SetHotKeyVolumePlus(const HotKey& hotkey);
        bool GetHotKeyVolumePlus(HotKey& hotkey);

        bool SetHotKeyVolumeMinus(const HotKey& hotkey);
        bool GetHotKeyVolumeMinus(HotKey& hotkey);

        bool SetHotKeyMuteAll(const HotKey& hotkey);
        bool GetHotKeyMuteAll(HotKey& hotkey);

        bool SetHotKeyVoiceGainPlus(const HotKey& hotkey);
        bool GetHotKeyVoiceGainPlus(HotKey& hotkey);

        bool SetHotKeyVoiceGainMinus(const HotKey& hotkey);
        bool GetHotKeyVoiceGainMinus(HotKey& hotkey);

        bool SetHotKeyMinRestore(const HotKey& hotkey);
        bool GetHotKeyMinRestore(HotKey& hotkey);
        /********* </shortcuts> *********/

        /********* <videocapture> *********/
        bool SetVideoCaptureDevice(const std::string& viddev);
        std::string GetVideoCaptureDevice();

        bool SetVideoCaptureFormat(int index);
        int GetVideoCaptureFormat(int nDefIndex);

        bool SetVideoCaptureFormat(const VideoFormat& capformat);
        bool GetVideoCaptureFormat(VideoFormat& capformat);

        bool SetVideoCodecBitrate(int bitrate);
        int GetVideoCodecBitrate(int nDefBitrate);

        bool SetVideoCaptureEnabled(bool enabled);
        bool GetVideoCaptureEnabled(bool def_value);
        /********* </videocapture> *********/

        /********* <latesthosts> ********/
        bool AddLatestHostEntry(const HostEntry& entry);
        bool RemoveLatestHostEntry(const HostEntry& entry);
        int GetLatestHostEntryCount();
        bool GetLatestHostEntry(int index, HostEntry& entry);
        /********* </latesthosts> *******/

        /********** <hostmanager> **********/
        bool AddHostManagerEntry(const HostEntry& entry);
        bool RemoveHostManagerEntry(const std::string entryname);
        int GetHostManagerEntryCount();
        bool GetHostManagerEntry(int index, HostEntry& entry);
        bool GetHostManagerEntry(std::string entryname, HostEntry& entry);
        /********** </hostmanager> **********/

        /********** <other> *********/
        bool SetLastMediaFile(const std::string& filename);
        std::string GetLastMediaFile();
        /********** </other> *********/
    protected:
        TiXmlElement* GetRootElement();
        TiXmlElement* GetMainElement();
        TiXmlElement* GetGeneralElement();
        TiXmlElement* GetWindowElement();
        TiXmlElement* GetClientElement();
        TiXmlElement* GetSoundSystemElement();
        TiXmlElement* GetEventsElement();
        TiXmlElement* GetVideoElement();
        TiXmlElement* GetAdvancedElement();
        TiXmlElement* GetShortCutsElement();
        TiXmlElement* GetHostManagerElement();
        TiXmlElement* GetLatestHostsElement();
        TiXmlElement* GetOtherElement();

        void PutHotKey(TiXmlElement& parent, const HotKey& hotkey);
        bool GetHotKey( const TiXmlElement& parent, HotKey& hotkey);
    };

    class TTFile : public XMLDocument
    {
    public:
       TTFile(const std::string& rootname) : 
          XMLDocument(rootname, TEAMTALK_XML_VERSION) { }

       void SetHostEntry(const HostEntry& entry);
       bool GetHostEntry(HostEntry& entry, int i);
       TiXmlElement* GetRootElement();
       bool HasClientSetup();
    };

}
#endif
