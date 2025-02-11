#ifndef CONV_EDGE_H_
#define CONV_EDGE_H_
#include "edge_with_weight.h"

/** Implements a convolutional edge.*/
class ConvEdge : public EdgeWithWeight {
 public:
  ConvEdge(const config::Edge& edge_config);
  virtual string GetDescription();
  virtual void SetMemory(Matrix& p);
  virtual void SetGradMemory(Matrix& p);
  virtual size_t GetParameterMemoryRequirement();
  virtual void ComputeUp(Matrix& input, Matrix& output, bool overwrite);
  virtual void ComputeDown(Matrix& deriv_output, Matrix& input,
                           Matrix& output, Matrix& deriv_input, bool overwrite);
  virtual void ComputeOuter(Matrix& input, Matrix& deriv_output);

  virtual void SetTiedTo(Edge* e);
  virtual void DisplayWeights();
  virtual void SetImageSize(int image_size_y, int image_size_x);
  virtual void FOV(int* size, int* sep, int* pad1, int* pad2) const;
 
  int GetKernelSize() const { return kernel_size_; }
  int GetStride() const { return stride_; }
  int GetPadding() const { return padding_; }
  int GetPartialSum() const { return partial_sum_; }
  bool GetSharedBias() const { return shared_bias_; }

 private:
  Matrix grad_weights_partial_sum_;
  int kernel_size_, stride_, padding_, partial_sum_;
  bool shared_bias_;
};
#endif
