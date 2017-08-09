# THIRD PARTY PACKAGES
set(THIRD_PARTY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/apps/3rdparty)
set(THIRD_PARTY_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}) # TODO: Remove this line

# add_custom_target(third_party)
# add_dependencies(third_party xerces wxpython httpd)

# XERCES
set(XERCES_REPO http://svn.apache.org/repos/asf/xerces/c/tags/Xerces-C_2_8_0)
# set(XERCES_REPO https://svn.apache.org/repos/asf/xerces/c/trunk)
set(XERCES_DIR ${CMAKE_CURRENT_BINARY_DIR}/xerces)
set(XERCES_INSTALL ${THIRD_PARTY_INSTALL_DIR}/xerces)
set(XERCES_ROOT ${XERCES_DIR}/source)
set(XERCES_SRC ${XERCES_ROOT}/src/xercesc)

ExternalProject_Add(xerces
    SVN_REPOSITORY ${XERCES_REPO}
    PREFIX ${XERCES_DIR}
    INSTALL_DIR ${XERCES_INSTALL}
    SOURCE_DIR ${XERCES_ROOT}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND
        # Build steps lumped together because XercesC environment variables
        # Using bash script prevents rebuilding if .installed file exists
        # I dislike this, but...
        sh ${CMAKE_SOURCE_DIR}/cmake/build_xerces.sh ${XERCES_SRC} ${XERCES_ROOT} ${XERCES_INSTALL}
)
set(XERCES_INCLUDE ${XERCES_INSTALL}/include)

# wxPython
set(WXPYTHON_URL
    http://cfhcable.dl.sourceforge.net/project/wxpython/wxPython/2.8.12.1/wxPython-src-2.8.12.1.tar.bz2)
set(WXPYTHON_DIR ${CMAKE_CURRENT_BINARY_DIR}/wxpython)
set(WXPYTHON_INSTALL ${CMAKE_INSTALL_PREFIX}/wxpython)
set(WXPYTHON_SRC ${WXPYTHON_DIR}/source)

ExternalProject_Add(wxpython
    URL ${WXPYTHON_URL}
    PREFIX ${WXPYTHON_DIR}
    SOURCE_DIR ${WXPYTHON_SRC}
    INSTALL_DIR ${WXPYTHON_INSTALL}
    CONFIGURE_COMMAND
        sh ${WXPYTHON_SRC}/configure --prefix=${WXPYTHON_INSTALL} --with-gtk --with-gnomeprint --with-opengl --enable-geometry --enable-graphics_ctx --enable-sound --with-sdl --enable-mediactrl --enable-display
    BUILD_COMMAND
        make &&
        make -C contrib/src/gizmos &&
        make -C contrib/src/stc
    INSTALL_COMMAND
        make install &&
        make -C contrib/src/gizmos install &&
        make -C contrib/src/stc install
)
set(WXPYTHON_FLAGS -I${WXPYTHON_INSTALL}/lib/wx/include/gtk2-ansi-release-2.8 -I${WXPYTHON_INSTALL}/include/wx-2.8 -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__)
set(WXPYTHON_INCLUDE ${WXPYTHON_INSTALL}/include/wx-2.8 ${WXPYTHON_INSTALL}/lib/wx/include/gtk2-ansi-release-2.8)
set(WXPYTHON_LIB ${WXPYTHON_INSTALL}/lib)

# HTTPD
set(HTTPD_URL http://apache.mirrors.pair.com//httpd/httpd-2.2.34.tar.gz)
set(HTTPD_DIR ${CMAKE_CURRENT_BINARY_DIR}/httpd)
set(HTTPD_INSTALL ${CMAKE_INSTALL_PREFIX}/httpd)
set(HTTPD_SRC ${HTTPD_DIR}/source)

ExternalProject_Add(httpd
    URL ${HTTPD_URL}
    PREFIX ${HTTPD_DIR}
    SOURCE_DIR ${HTTPD_SRC}
    INSTALL_DIR ${HTTPD_INSTALL}
    CONFIGURE_COMMAND
        ${HTTPD_SRC}/configure --prefix=${HTTPD_INSTALL} --enable-rewrite --enable-dav
    BUILD_COMMAND
        make
    INSTALL_COMMAND
        make install
)

# ActiveMQ
set(ACTIVEMQ_URL
    https://github.com/FriendsofECCE/ECCE/raw/develop/build/3rdparty-dists/apache-activemq-5.1.0-bin.tar.bz2)
set(ACTIVEMQ_DIR ${CMAKE_CURRENT_BINARY_DIR}/activemq)
set(ACTIVEMQ_INSTALL ${CMAKE_INSTALL_PREFIX}/activemq)
set(ACTIVEMQ_SRC ${ACTIVEMQ_DIR}/source)

ExternalProject_Add(activemq
    URL ${ACTIVEMQ_URL}
    PREFIX ${ACTIVEMQ_DIR}
    SOURCE_DIR ${ACTIVEMQ_INSTALL}
    CONFIGURE_COMMAND
        echo "It's a bin distrobution, so no build."
    BUILD_COMMAND
        echo "No build either."
    INSTALL_COMMAND
        echo "And no install."
)
