#ifndef MAXPOOL_EDGE_H_
#define MAXPOOL_EDGE_H_
#include "edge.h"

/** Implements a Max-pool edge.*/
class MaxPoolEdge : public Edge {
 public:
  MaxPoolEdge(const config::Edge& edge_config);
  virtual string GetDescription();
  virtual void SetTiedTo(Edge* e);
  virtual void ComputeUp(Matrix& input, Matrix& output, bool overwrite);
  virtual void ComputeDown(Matrix& deriv_output, Matrix& input,
                           Matrix& output, Matrix& deriv_input, bool overwrite);

  virtual void SetImageSize(int image_size_y, int image_size_x);
  virtual void FOV(int* size, int* sep, int* pad1, int* pad2) const;

  int GetKernelSize() const { return kernel_size_; }
  int GetStride() const { return stride_; }
  int GetPadding() const { return padding_; }

 private:
  int kernel_size_, stride_, padding_;
};
#endif
