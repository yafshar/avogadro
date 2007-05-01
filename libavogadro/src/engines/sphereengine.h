/**********************************************************************
  BSEngine - Engine for "balls and sticks" display

  Copyright (C) 2006 by Geoffrey R. Hutchison
  Some portions Copyright (C) 2006 by Donald E. Curtis
  Some portions Copyright (C) 2007 by Marcus D. Hanwell

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.sourceforge.net/>

  Some code is based on Open Babel
  For more information, see <http://openbabel.sourceforge.net/>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#ifndef __BSENGINE_H
#define __BSENGINE_H

#include <avogadro/global.h>
#include <avogadro/engine.h>
#include <avogadro/sphere.h>
#include <avogadro/cylinder.h>

#include <openbabel/mol.h>

#include <QGLWidget>
#include <QObject>
#include <QStringList>
#include <QImage>

namespace Avogadro {

  //! Sphere Engine class.
  class BSEngine : public Engine
  {
    Q_OBJECT

    public:
      //! Constructor
      BSEngine(QObject *parent=0) : Engine(parent), m_setup(false) {}
      //! Deconstructor
      ~BSEngine() {}

      //! \name Description methods
      //@{
      //! @return engine name
      QString name() { return(QString(tr("Sphere"))); }
      //! @return engine description
      QString description() { return(QString(tr("Renders atoms as spheres"))); }
      //@}

      //! \name Render Methods
      //@{
      //! Render an Atom.
      bool render(const Atom *a);
      //! Render a Bond.
      bool render(const Bond *b);
      //! Render a Molecule.
      bool render(const Molecule *m);

      bool render(GLWidget *gl);
      //@}

    private:
      Sphere m_sphere;
      Cylinder m_cylinder;

      bool m_setup; //!< Whether the sphere and cylinder objects have been setup
  };

  //! Generates instances of our BSEngine class
  class BSEngineFactory : public QObject, public EngineFactory
  {
    Q_OBJECT
    Q_INTERFACES(Avogadro::EngineFactory)

    public:
      Engine *createInstance(QObject *parent = 0) { return new BSEngine(parent); }
  };

} // end namespace Avogadro

#endif
