//**************************************************************************************************
//
//     OSSIM Open Source Geospatial Data Processing Library
//     See top level LICENSE.txt file for license information
//
//**************************************************************************************************

#include <iostream>
#include <map>
using namespace std;

#include <ossim/init/ossimInit.h>
#include <ossim/base/ossimArgumentParser.h>
#include <ossim/base/ossimApplicationUsage.h>
#include <ossim/base/ossimStdOutProgress.h>
#include <ossim/base/ossimTimer.h>
#include <ossim/base/ossimString.h>
#include <ossim/util/ossimUtilityFactory.h>
#include <ossim/base/ossimException.h>

int main(int argc, char *argv[])
{
   ossimArgumentParser ap(&argc, argv);
   ap.getApplicationUsage()->setApplicationName(argv[0]);

   try
   {
      // Initialize ossim stuff, factories, plugin, etc.
      ossimInit::instance()->initialize(ap);

      ossimUtilityFactory* factory = ossimUtilityFactory::instance();

      map<string, string> capabilities;
      factory->getCapabilities(capabilities);

      double t0 = ossimTimer::instance()->time_s();
      t0 = ossimTimer::instance()->time_s();

   }
   catch  (const ossimException& e)
   {
      ossimNotify(ossimNotifyLevel_FATAL)<<e.what()<<endl;
      exit(1);
   }
   catch( ... )
   {
      cerr << "Caught unknown exception!" << endl;
   }

   //double dt = ossimTimer::instance()->time_s() - t0;
   //cout << argv[0] << "Elapsed Time: " << dt << " s\n" << endl;
   exit(0);
}
