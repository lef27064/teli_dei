﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;
using System.Xml.Linq;
using System.Configuration;
using System.Net;
using System.Diagnostics;
using System.Windows.Forms;



  
 /*      private const string DownloadsList = @"http://code.google.com/p/wotdossier/downloads/list";
        private const string VersionUrl = "http://www.pogoni.gr/teli_dei/files/version.txt";*/
      
namespace VersionHelper
{
    public class VersionHelper
    {
        private string MSIFilePath = Path.Combine(Environment.CurrentDirectory, "HoustersCrawler.msi");
        private string CmdFilePath = Path.Combine(Environment.CurrentDirectory, "Install.cmd");
        private string MsiUrl = "http://www.pogoni.gr";

        public bool CheckForNewVersion()
        {
            MsiUrl = GetNewVersionUrl();
            return MsiUrl.Length > 0;
        }

        public void DownloadNewVersion()
        {
            DownloadNewVersion(MsiUrl);
            CreateCmdFile();
            RunCmdFile();
            ExitApplication();
        }

        private string GetNewVersionUrl()
        {
            var currentVersion = Convert.ToInt32(ConfigurationManager.AppSettings["Version"]);
            //get xml from url.
            var url = ConfigurationManager.AppSettings["VersionUrl"].ToString();
            var builder = new StringBuilder();
            using (var stringWriter = new StringWriter(builder))
            {
                using (var xmlReader = new XmlTextReader(url))
                {
                    var doc = XDocument.Load(xmlReader);
                    //get versions.
                    var versions = from v in doc.Descendants("version")
                                   select new
                                   {
                                       Name = v.Element("name").Value,
                                       Number = Convert.ToInt32(v.Element("number").Value),
                                       URL = v.Element("url").Value,
                                       Date = Convert.ToDateTime(v.Element("date").Value)
                                   };
                    var version = versions.ToList()[0];
                    //check if latest version newer than current version.
                    if (version.Number > currentVersion)
                    {
                        return version.URL;
                    }
                }
            }
            return String.Empty;
        }

        private void DownloadNewVersion(string url)
        {
            //delete existing msi.
            if (File.Exists(MSIFilePath))
            {
                File.Delete(MSIFilePath);
            }
            //download new msi.
            using (var client = new WebClient())
            {
                client.DownloadFile(url, MSIFilePath);
            }
        }

        private void CreateCmdFile()
        {
            //check if file exists.
            if (File.Exists(CmdFilePath))
                File.Delete(CmdFilePath);
            //create new file.
            var fi = new FileInfo(CmdFilePath);
            var fileStream = fi.Create();
            fileStream.Close();
            //write commands to file.
            using (TextWriter writer = new StreamWriter(CmdFilePath))
            {
                writer.WriteLine(@"msiexec /i HoustersCrawler.msi /quiet");
            }
        }

        private void RunCmdFile()
        {//run command file to reinstall app.
            var p = new Process();
            p.StartInfo = new ProcessStartInfo("cmd.exe", "/c Install.cmd");
            p.StartInfo.CreateNoWindow = true;
            p.Start();
            //p.WaitForExit();
        }

        private void ExitApplication()
        {//exit the app.
            Application.Exit();
        }
    }
}