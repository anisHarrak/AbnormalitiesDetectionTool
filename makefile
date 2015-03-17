#
# Compiles on: 
#  Any windows machine (via CYGWIN)
#  lindev01 (Linux 2.4)
#  lindev02 (Linux 2.6)
#  ibiscus  (Solaris 2.8)
#  orion    (Solaris 2.9)
#  narcisse (Solaris 2.10)
#  sun1x86  (Solaris 2.10 / i86)
#

BOOST_BUILD_VERSION = 2.0.0

ifeq (CYGWIN,$(findstring CYGWIN,$(shell uname)))
	STATIC_DEBUG   = scstaticdebug
	STATIC_RELEASE = scstaticrelease
	BJAM_ENV = export BOOST_BUILD_PATH=w:/shrdlibs/boost-build/$(BOOST_BUILD_VERSION) ; export GL_DELIVERY_PATH=w:/delivery
else
ifeq (Sun,$(findstring Sun,$(shell uname)))
	BJAM_ENV = BOOST_BUILD_PATH=/sr/gldev/shrdlibs/boost-build/$(BOOST_BUILD_VERSION); export BOOST_BUILD_PATH; GL_DELIVERY_PATH=/sr/gldev/delivery; export GL_DELIVERY_PATH
else
	BJAM_ENV = export BOOST_BUILD_PATH=/sr/gldev/shrdlibs/boost-build/$(BOOST_BUILD_VERSION) ; export GL_DELIVERY_PATH=/sr/gldev/delivery
endif
endif


debug:
	$(BJAM_ENV); bjam scdebug

clean:
	$(BJAM_ENV); bjam clean

cleanall:
	rm -rf bin

