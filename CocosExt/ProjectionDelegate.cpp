
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
: m_origin( 0.0f, 0.0f )
{
}

ProjectionDelegate::~ProjectionDelegate()
{
}

void ProjectionDelegate::updateProjection()
{
	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
	CCSize sizePoint = CCDirector::sharedDirector()->getWinSize();

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
	kmVec3Fill( &eye, m_origin.x, m_origin.y, zeye );
	kmVec3Fill( &center, m_origin.x, m_origin.y, 0.0f );
	kmVec3Fill( &up, 0.0f, 1.0f, 0.0f);
	kmMat4LookAt(&matrixLookup, &eye, &center, &up);
	kmGLMultMatrix(&matrixLookup);
}

void ProjectionDelegate::setOrigin( float fX, float fY )
{
	m_origin.x = fX;
	m_origin.y = fY;

	updateProjection();
}

};

