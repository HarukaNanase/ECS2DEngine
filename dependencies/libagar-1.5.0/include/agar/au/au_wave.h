/*	Public domain	*/

#ifndef _AGAR_AU_WAVE_H_
#define _AGAR_AU_WAVE_H_

#include <sndfile.h>

#include <agar/au/begin.h>

typedef struct au_wave {
	AG_Mutex lock;			/* Lock on audio data */
	Uint flags;
	SNDFILE *file;			/* Associated file */
	SF_INFO info;			/* Format information */
	float *frames;			/* Uncompressed audio data */
	Uint  nFrames;			/* Number of frames */
	int ch;				/* Number of channels */
	float      *vizFrames;		/* Reduced visualization data */
	sf_count_t nVizFrames;		/* Visualization # frames total */
	double peak;			/* Signal peak */
} AU_Wave;

typedef struct au_wave_state {
	int play;			/* Sample is playing */
	sf_count_t pos;			/* Playback position */
} AU_WaveState;

/* Begin generated block */
__BEGIN_DECLS
extern DECLSPEC AU_Wave *AU_WaveNew(void);
extern DECLSPEC AU_Wave *AU_WaveFromFile(const char *);
extern DECLSPEC void AU_WaveFree(AU_Wave *);
extern DECLSPEC void AU_WaveFreeData(AU_Wave *);
extern DECLSPEC int AU_WaveLoad(AU_Wave *, const char *);
extern DECLSPEC int AU_WaveGenVisual(AU_Wave *, int);
__END_DECLS
/* Close generated block */

#include <agar/au/close.h>
#endif /* _AGAR_AU_WAVE_H_ */
