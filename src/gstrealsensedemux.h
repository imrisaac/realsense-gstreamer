/* 
 */

#ifndef __GST_RSDEMUX_H__
#define __GST_RSDEMUX_H__

#include <gst/gst.h>
#include "common.hpp"

G_BEGIN_DECLS

#define GST_TYPE_RSDEMUX \
  (gst_rsdemux_get_type())
#define GST_RSDEMUX(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_RSDEMUX,GstRSDemux))
#define GST_RSDEMUX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_RSDEMUX,GstRSDemuxClass))
#define GST_IS_RSDEMUX(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_RSDEMUX))
#define GST_IS_RSDEMUX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_RSDEMUX))


typedef struct _GstRSDemux GstRSDemux;
typedef struct _GstRSDemuxClass GstRSDemuxClass;

struct _GstRSDemux {
  GstElement     element;

  GstPad        *sinkpad;
  GstPad        *colorsrcpad = nullptr;
  GstPad        *depthsrcpad = nullptr;
  GstPad        *imusrcpad = nullptr;
  
  /* video params */
  RSHeader header;
  gint           in_height;
  gint           in_width;
  gint           in_stride_bytes;

  gint           frame_count = 0;
};

struct _GstRSDemuxClass 
{
  GstElementClass parent_class;
};

GType gst_rsdemux_get_type (void);

G_END_DECLS

#endif /* __GST_RSDEMUX_H__ */