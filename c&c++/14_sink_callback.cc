/******************************************************************************
 * This is used to demonstrate how to use sink instead of callback function
 * in C++ coding style
 *
 * COMPILATION: g++ -o 14_sink_callback 14_sink_callback.cc
 *
 * REFERENCE:
 * https://blog.csdn.net/birdflyto206/article/details/51126876
 ******************************************************************************/

#include <iostream>

class IDownloadSink
{
public:
    virtual void OnDownloadFinished(const char *pURL,bool bOK) = 0;
};

class CMyDownloader
{
public:
    CMyDownloader (IDownloadSink *pSink)
        :m_pSink(pSink)
    {

    }

    void DownloadFile(const char* pURL)
    {
        std::cout<<"downloading..."<<pURL<<""<<std::endl;
        if(m_pSink!=NULL)
        {
            m_pSink->OnDownloadFinished(pURL,true);
        }
    }

private:
    IDownloadSink *m_pSink;
};


class CMyFile:public IDownloadSink
{
public:
    void download()
    {
        CMyDownloader downloader(this);
        downloader.DownloadFile("www.baidu.com");
    }

    virtual void OnDownloadFinished(const char *pURL,bool bOK)
    {
        std::cout<<"onDownloadFinished..."<<pURL<<"   status:"<<bOK<<std::endl;
    }
};

int main()
{
    CMyFile *file = new CMyFile();
    file->download();
    delete file;

    return 0;
}
