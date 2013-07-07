
#include "ProjectionDelegate.h"

#include "CCDirector.h"
#include "kazmath/kazmath.h"
#include "kazmath/GL/matrix.h"

namespace ProjG
{

static ProjectionDelegate s_sharedProjectionDelegate;


ProjectionDelegate* ProjectionDelegate::sharedPointer()
{
	return &s_sharedProjectionDelegate;
}

ProjectionDelegate::ProjectionDelegate()
: m_center( 0.0f, 0.0f )
{
}

ProjectionDelegate::~ProjectionDelegate()
{
}

void ProjectionDelegate::updateProjection()
{
	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();

	float zeye = CCDirector::sharedDirector()->getZEye();

	kmMat4 matrixPerspective, matrixLookup;

	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLLoadIdentity();

	// issue #1334
	kmMat4PerspectiveProjection( &matrixPerspective, 60, (GLfloat)size.width/size.height, 0.1f, zeye*2);
	// kmMat4PerspectiveProjection( &matrixPerspective, 60, (GLfloat)size.width/size.height, 0.1f, 1500);

	kmGLMultMatrix(&matrixPerspective);

	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLLoadIdentity();
	kmVec3 eye, center, up;
	kmVec3Fill( &eye, m_center.x, m_center.y, zeye );
	kmVec3Fill( &center, m_center.x, m_center.y, 0.0f );
	kmVec3Fill( &up, 0.0f, 1.0f, 0.0f);
	kmMat4LookAt(&matrixLookup, &eye, &center, &up);
	kmGLMultMatrix(&matrixLookup);
}

void ProjectionDelegate::setCenter( float fX, float fY )
{
	m_center.x = fX;
	m_center.y = fY;

	updateProjection();
}

void ProjectionDelegate::resetCenter( )
{
	CCSize sizePoint = CCDirector::sharedDirector()->getWinSize();
	setCenter( sizePoint.width * 0.5f, sizePoint.height * 0.5f );

}

};

